# CloudRedirect — edição Edileno (experimental)

Este repositório importa o código aberto de [CloudRedirect-Community](https://github.com/Contrary7/CloudRedirect-Community) a partir de um commit fixo, aplica uma correção experimental de sincronização e compila um aplicativo **Windows x64** no GitHub Actions.

## Objetivo

Gerar `CloudRedirect.exe` e `cloud_redirect.dll` em um artefato de download. O executável inclui a DLL embutida e mantém a instalação na Steam realizada pela interface original. Os arquivos separados são fornecidos para conferência.

## Download

Abra a aba **Actions**, escolha **CloudRedirect Windows x64** e baixe o artefato **CloudRedirect-Edileno-win-x64** de uma execução bem-sucedida.

## Segurança dos saves

**Experimental. Não substitua os saves sem backup.** Compile e teste usando primeiro uma cópia dos saves locais e remotos. Um build aprovado não comprova que a Steam e o Google Drive estão sincronizando corretamente. O Valheim foi adicionado à Steam por LUA, e esse cenário exige teste manual.

O GitHub Action registra a origem do código e interrompe a execução em caso de falha na aplicação da correção ou na compilação. Usa somente o código-fonte público de um commit fixado, nunca um executável antigo reaproveitado com o nome de versão nova.

Base comunitária: `Contrary7/CloudRedirect-Community`, commit `0be5f506cf45303e0a964ada7625a7cdcfff6850`. Consulte a licença original `LICENSE` após a importação automática dos fontes.

**Status:** correção experimental; funcionamento no Windows/Steam/Google Drive ainda não validado.
