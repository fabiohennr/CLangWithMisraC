# Configurando Ambiente Linux para Desenvolvimento C/C++ com uso da ferramenta de análise estática Clang em conjunto com padronização MISRA C

Este tutorial descreve o passo a passo para guiá-lo na configuração de um ambiente Linux para desenvolvimento C/C++, incluindo a instalação de ferramentas essenciais como `clang`, `clang-tidy`, `tmux` e outras dependências para facilitar a depuração do seu código no formato MISRA C.

## Opção 1: Usando Docker (Recomendado para Configuração Rápida)

Você pode configurar este ambiente rapidamente usando Docker. Uma imagem pré-configurada está disponível no Docker Hub.

### 1.1 **Instale o Docker:**

Se você ainda não tem o Docker instalado, siga as instruções de instalação para sua distribuição Linux em [docs.docker.com](https://docs.docker.com/engine/install/).

### 1.2. **Execute o Contêiner Docker:**

Execute o seguinte comando no terminal para baixar e executar a imagem Docker:

```bash
docker run -it fabiohennr/clang_with_misrac
```

### 1.3. **Acesse o Ambiente de Desenvolvimento:**

Após a execução do comando, você estará dentro do contêiner Docker com o ambiente de desenvolvimento pronto para uso.

**Agora pule para o passo 2.6 para execução do teste de uso da ferramenta.**

---

## Opção 2: Configuração Manual (Para Personalização Avançada)

Se você preferir configurar o ambiente manualmente, siga os passos abaixo:

### **Pré-requisitos**

- Um sistema Linux baseado em Debian/Ubuntu (outras distribuições podem exigir adaptações nos comandos de instalação).
- Acesso ao terminal com privilégios de superusuário (`sudo`).

### **Passos**

#### 2.1. **Atualizar o Sistema:**

Abra o terminal e execute os seguintes comandos para atualizar a lista de pacotes e atualizar os pacotes instalados:

```bash
sudo apt update
```

#### 2.2. **Instalar Ferramentas Essenciais:**

Instale as ferramentas de desenvolvimento e utilitários necessários:

```bash
sudo apt install -y build-essential tmux nano clang clang-tools clang-tidy
```

- `build-essential`: Pacote que contém as ferramentas essenciais para compilação de software.
- `tmux`: Multiplexador de terminal para gerenciar múltiplas sessões e painéis para facilitar a visualização dos testes.
- `nano`: Visualizador e editor de texto baseado em terminal para Linux.
- `clang`, `clang-tools`, `clang-tidy`: Compilador Clang e ferramentas de análise estática e incorporação da verificação MISRA C.

#### 2.3. **Verificar Instalação:**

Verifique se as ferramentas foram instaladas corretamente executando os seguintes comandos:

```bash
clang --version
clang-tidy --version
tmux --version
nano --version
```

Cada comando deve exibir a versão da ferramenta instalada.

#### 2.4. **Clonar o Repositório:**

Clone o repositório contendo exemplos e configurações pré-configuradas para análise MISRA C:

```bash
git clone https://github.com/fabiohennr/CLangWithMisraC.git
```

Entre na pasta do repositório clonado:

```bash
cd CLangWithMisraC
```

#### 2.5. **Usar Tmux para Múltiplas Janelas:**

Inicie uma sessão `tmux`:

```bash
tmux
```

- Divida a janela horizontalmente: `Ctrl+b %`
- Navegue entre os painéis com `Ctrl+b <seta>`.
- Em cada painel, você pode executar comandos em diferentes pastas de exemplo e visualizar a diferença entre eles.

#### 2.6. **Exibir arquivos do repositório:**

- Execute o comando para listar os arquivos da pasta do repositório para confirmar se foi tudo carregado.
- O resultado devera ser o seguinte:

```bash
ls
Dockerfile  README.md  example1  example2  example3
```


#### 2.7. **Executar Clang-Tidy:**

Entre em alguma pasta de arquivo, por exemplo:

```bash
cd example1
```

Execute o `clang-tidy` para analisar o código correspondente em cada pasta, por exemplo:

```bash
clang-tidy -checks='misra-*' example1.c -- -I/path/to/includes -DDEFINE1 -DDEFINE2
```

A saída exibirá as violações MISRA C encontradas.
Se nada for exibido significa que não foram encontradas nenhum divergência no código.


---

## Pontos de atenção
- O uso do Clang com clang-tidy para verificação do padrão não é certificado pelo MISRAC. Portanto não traz garantia de que irá cobrir todas as regras da norma.
- Aqui mostro, portanto, apenas uma simples aplicação para exemplificar e facilidar uma imersão na ferramenta e ao padrão.
- **Pontos positivos:** É Gratuito. Faz verificação de análise estática de forma rápida. Pode ser um bom ponto de partida para verificação MISRAC para ferramentas certificadas como Polyspace, LDRA, PRQA (QA-C), Astrée e Coverity (cobrem 100% das regras e são certificadas)
- **Pontos negativos:** Não cobre 100% do padrão MISRA C e não possui certificação.

## Recursos Adicionais

- **Documentação do Clang:** [https://clang.llvm.org/docs/](https://clang.llvm.org/docs/)
- **Documentação do Clang-Tidy:** [https://clang.llvm.org/extra/clang-tidy/](https://clang.llvm.org/extra/clang-tidy/)
- **Documentação do Tmux:** [https://github.com/tmux/tmux/wiki](https://github.com/tmux/tmux/wiki)
- **Site Oficial da MISRA:** [https://www.misra.org.uk/](https://www.misra.org.uk/)

---

Este tutorial fornece uma base sólida para começar a desenvolver em C/C++ em um ambiente Linux com Clang e MISRA C. Adapte os comandos e configurações conforme necessário para atender aos requisitos específicos do seu projeto.
