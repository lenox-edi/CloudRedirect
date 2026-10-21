# CloudRedirect — edição Edileno (base comunitária)

Este repositório preserva a implementação comunitária do CloudRedirect v2.6.5 para **todos os jogos adicionados por `.lua` à Steam**. Não existem regras nem caminhos exclusivos para Valheim.

**Origem do motor:** [Contrary7/CloudRedirect-Community](https://github.com/Contrary7/CloudRedirect-Community), que preserva o código de Selectively11/CloudRedirect. Licença MIT conforme `LICENSE`.

## Arquivos para Windows

Abra a aba [Actions](https://github.com/lenox-edi/CloudRedirect/actions/workflows/windows-x64.yml) e baixe o artefato `CloudRedirect-Community-Edileno-win-x64` de uma compilação **verde**. Dentro do ZIP estão apenas:
- `CloudRedirect.exe`
- `cloud_redirect.dll`

O EXE inclui a DLL correspondente embutida, por isso **não é necessário copiá-la à Steam manualmente**. A DLL separada é disponibilizada para conferência.

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
