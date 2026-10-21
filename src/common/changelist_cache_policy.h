#pragma once
#include <string>
#include <unordered_set>

// Evita indicar "já sincronizado" enquanto a Steam ainda não possui todos
// os arquivos previamente anunciados pela nuvem.
namespace ChangelistCachePolicy {
template <typename HasBlob>
bool CanSuppressRepeat(bool validRemoteCN,
                       const std::unordered_set<std::string>& expected,
                       HasBlob hasBlob) {
    if (!validRemoteCN || expected.empty()) return false;
    for (const auto& name : expected)
        if (!hasBlob(name)) return false;
    return true;
}

inline bool MayMarkFull(bool authoritativeCloudState, bool fetchFailed, bool isDelta) {
    return authoritativeCloudState && !fetchFailed && !isDelta;
}
} // namespace ChangelistCachePolicy
