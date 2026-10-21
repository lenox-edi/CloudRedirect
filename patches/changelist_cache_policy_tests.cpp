#include "changelist_cache_policy.h"
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_set>

int main() {
    using namespace ChangelistCachePolicy;
    const std::unordered_set<std::string> remote{"character.fch", "world.db"};
    const auto allPresent = [](const std::string&) { return true; };
    const auto partial = [](const std::string& s) { return s != "world.db"; };

    assert(!CanSuppressRepeat(false, remote, allPresent));
    assert(!CanSuppressRepeat(true, {}, allPresent));
    assert(!CanSuppressRepeat(true, remote, partial));
    assert(CanSuppressRepeat(true, remote, allPresent));
    assert(!MayMarkFull(false, false, false));
    assert(!MayMarkFull(true, true, false));
    assert(!MayMarkFull(true, false, true));
    assert(MayMarkFull(true, false, false));
    std::cout << "8 checks passed" << std::endl;
    return 0;
}
