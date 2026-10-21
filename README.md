# CloudRedirect — edição Edileno (base comunitária)

Este repositório preserva a implementação comunitária do CloudRedirect v2.6.5 para **todos os jogos adicionados por `.lua` à Steam**. Não existem regras nem caminhos exclusivos para Valheim.

**Origem do motor:** [Contrary7/CloudRedirect-Community](https://github.com/Contrary7/CloudRedirect-Community), que preserva o código de Selectively11/CloudRedirect. Licença MIT conforme `LICENSE`.

## Arquivos para Windows

Abra a aba [Actions](https://github.com/lenox-edi/CloudRedirect/actions/workflows/windows-x64.yml) e baixe o artefato `CloudRedirect-Community-Edileno-win-x64` de uma compilação **verde**. Dentro do ZIP estão apenas:
- `CloudRedirect.exe`
- `cloud_redirect.dll`

O EXE inclui a DLL correspondente embutida, por isso **não é necessário copiá-la à Steam manualmente**. A DLL separada é disponibilizada para conferência.

## GitHub Packages (GHCR)

O [pacote CloudRedirect](https://github.com/users/lenox-edi/packages?repo_name=CloudRedirect) é publicado pelo GitHub Actions como **artefato OCI** `ghcr.io/lenox-edi/cloudredirect:community-2.6.5`, contendo os dois arquivos de Windows. É um pacote de distribuição, **não é um contêiner executável**.

Para extrair os arquivos com [ORAS](https://oras.land/):

```powershell
oras pull ghcr.io/lenox-edi/cloudredirect:community-2.6.5
```

Para baixar sem instalar ORAS, use a aba **Actions**, escolha uma execução aprovada e baixe o ZIP `CloudRedirect-Community-Edileno-win-x64`.

A primeira publicação de pacotes no GHCR pode ficar privada por padrão; o proprietário pode ajustar sua visibilidade em **Packages → Package settings → Change visibility**. A publicação usa o token do próprio repositório para vincular o pacote.

## Como usar — qualquer jogo .lua

1. Faça backup dos saves e saia completamente da Steam.
2. Execute `CloudRedirect.exe`, selecione **CloudRedirect** (não o modo STfixer).
3. Na aba **Setup**, use **Run All Patches** para implantar a DLL na pasta da Steam. A integração que carrega a DLL precisa estar ativa; apenas ter o arquivo na pasta não é suficiente.
4. Na aba **Cloud Provider**, selecione o Google Drive (ou outro provedor) e faça login.
5. Inicie a Steam novamente e teste a sincronização em um jogo instalado via LUA antes de usar os demais.

O motor da comunidade intercepta as chamadas da Steam Cloud para os apps adicionados via LUA, incluindo jogos que usam AutoCloud. Jogos possuídos legitimamente continuam usando a Steam Cloud normal, como no original.

## Limitações e segurança

O código nativo foi restaurado à versão comunitária, **sem o patch experimental de cache da versão anterior**. O repositório comunitário não fornece um release binário oficial neste momento; o workflow compila a DLL diretamente dos fontes.

A compilação **não comprova** funcionamento da integração Steam, Google Drive ou sistema de LUA. Se a Steam continuar exibindo erro de sincronização, o diagnóstico precisa ser feito com os logs da DLL e com o estado real da instalação. Não force uma sincronização ou substitua saves sem backup.

Os utilitários auxiliares de migração Steam 760 não estão incluídos no repositório público da comunidade e são opcionais para a sincronização cotidiana, mas recursos de migração podem ficar indisponíveis.

Licença: MIT, consulte [LICENSE](LICENSE).

## Diagnóstico de sincronização (outubro de 2026)

A partir do `cloud_redirect.log` foi observado um caso em que a Steam iniciou no modo **local-only** (sem `config.json`), aceitou uploads locais e mais tarde conectou ao Google Drive. Os lotes **não foram publicados**, deixando `clientCN` à frente do `cloudCN`.

**Correção preventiva no código da DLL:** `HandleBeginBatch` agora falha antes de atribuir um número de sincronização quando o provedor não está disponível/autenticado; `HandleCompleteBatch` retorna erro à Steam quando não consegue concluir a publicação. Isso preserva os saves e evita afirmar sincronização inexistente. A correção **não resolve automaticamente conflitos que já existiam antes dela**.

**Como diagnosticar:** abra o arquivo `cloud_redirect.log` na pasta da Steam e procure por `provider=none`, `provider=Google Drive`, `BLOCKED -- cloud provider`, `staged promotion failed` e `clientCN`. `provider=Google Drive` apenas confirma que o provedor foi inicializado; não prova que todos os saves foram sincronizados.

**Antes de corrigir um conflito existente:** copie para um local separado a pasta `Steam\\cloud_redirect`, a pasta `Steam\\userdata`, os saves reais do jogo e um backup/exportação do provedor. **Não apague remotecache.vdf, não ajuste change numbers à mão e não rode o comando `publish-full-manifest` como tentativa aleatória de reparo.** Esse comando não garante que todos os blobs associados existam na nuvem. Escolha a versão a preservar somente após comparar os arquivos locais e remotos.

