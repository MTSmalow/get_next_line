*Este projeto foi criado como parte do currículo da 42 por edmedeir.*

# get_next_line

Função em C que lê uma linha por vez de um file descriptor, usando variável estática para preservar o estado entre chamadas.

## Descrição

O **get_next_line** implementa uma função que, a cada chamada, retorna a próxima linha disponível no file descriptor informado — incluindo o `\n` final, quando presente. Ao atingir o fim do arquivo ou em caso de erro, retorna `NULL`.

O projeto ensina na prática o conceito de **variáveis estáticas** em C: como manter estado entre execuções de uma função sem recorrer a variáveis globais.

```c
char *get_next_line(int fd);
```

Funciona tanto com arquivos quanto com a entrada padrão (`stdin`). O tamanho do buffer de leitura é configurável em tempo de compilação via `-D BUFFER_SIZE=n`.

## Uso

```c
#include "get_next_line.h"

int main(void)
{
    int     fd;
    char    *line;

    fd = open("arquivo.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## Algoritmo

A função mantém uma **variável estática** (`reds`) que funciona como buffer residual: armazena os bytes lidos que ainda não foram entregues como linha.

A cada chamada, o fluxo é:

1. `read_fd` lê o fd em chunks de `BUFFER_SIZE` bytes, concatenando ao buffer residual até encontrar um `\n` ou atingir EOF.
2. `ext_l` extrai do buffer tudo até o `\n` (inclusive) e retorna como a linha atual.
3. `cln_r` limpa o buffer residual, mantendo apenas o que veio após o `\n` para a próxima chamada.

Essa abordagem evita ler o arquivo inteiro de uma vez — lê-se o mínimo necessário a cada chamada, o que é eficiente e correto independentemente do valor de `BUFFER_SIZE`.

A escolha de uma única variável estática (em vez de estruturas ou arrays) mantém o código simples e dentro dos limites da Norminette, ao custo de suportar apenas um fd por vez na versão mandatória.

## Instruções

### Compilação

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o programa
```

O `BUFFER_SIZE` padrão definido no header é `42`. Pode ser sobrescrito em tempo de compilação para qualquer valor positivo.

## Recursos

- [man 2 read — Linux man pages](https://man7.org/linux/man-pages/man2/read.2.html)
- [man 3 malloc — Linux man pages](https://man7.org/linux/man-pages/man3/malloc.3.html)
- [Static variables in C — GeeksforGeeks](https://www.geeksforgeeks.org/static-variables-in-c/)
- [File descriptors explained](https://www.bottomupcs.com/file_descriptors.xhtml)

### Uso de IA

A IA (Claude) foi utilizada pontualmente como suporte, não como fonte de respostas diretas:

- **Dúvidas conceituais**: comportamento de variáveis estáticas entre chamadas e gerenciamento do buffer residual, sem solicitar implementações.
- **Revisão de raciocínio**: validação do entendimento sobre o ciclo leitura → extração → limpeza do buffer.

As implementações foram desenvolvidas de forma independente, com base nas man pages e nos testes contra diferentes valores de `BUFFER_SIZE`.