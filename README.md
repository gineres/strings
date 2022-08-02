[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=7916157&assignment_repo_type=AssignmentRepo)

# Lista de Exercícios 1 — Unidade 2

Está atividade é **individual** e corresponde à metade da nota da segunda unidade.

Implemente uma aplicação em C++ para representação de cadeias de caracteres. A cadeia de caracteres deve ser representada por uma classe com ao menos três construtores: um sem parâmetros, representando a cadeia vazia; um recebendo um literal (string entre aspas duplas) da linguagem C++ de modo que a cadeia deve representar o literal indicado; e o último recebendo um objeto da mesma classe de modo a cadeia deve ser uma cópia do argumento.

Escolha a representação dos atributos entre o objeto std::vector, o objeto std::array ou um array da linguagem C++. O nível de dificuldade da implementação está diretamente relacionada com a representação escolhida sendo a mais fácil usando o std::vector e a mais difícil sem o uso de objetos. Neste último, é necessário o uso de alocação dinâmica de memória para redimensionamento da cadeia.

Após a escolha da representação dos atributos, você deve implementar os seguintes métodos:
1. Tamanho da cadeia, isto é, a quantidade de caracteres presentes. É opcional a substituição desse método por um atributo que não pode ser alterado fora da classe, ou seja, atributo de somente leitura;
2. Método de entrada de dados, isto é, a cadeia é preenchida com os caracteres da entrada padrão que representam uma palavra (termina num espaço ou quebra de linha). É opcional a sobrecarga do operador de entrada de dados;
3. Método de saída de dados, isto é, os caracteres da cadeia são exibidos na saída padrão. É opcional a sobrecarga do operador de saída de dados;
4. Método de entrada de dados de uma linha inteira, isto é, todos os caracteres da entrada de dados padrão são recuperados e armazenados na cadeia até encontrar o caractere de quebra de linha ou de final de entrada de dados, sendo que estes últimos não fazem parte da cadeia;
5. Comparação entre cadeias de caracteres. É opcional a sobrecarga do operador de igualdade;
6. Método de aparar espaços, isto é, ele deve remover todos os espaços, tabulações e quebra de linhas que aparecem no início e no final da cadeia até encontrar um caractere diferente;
7. Métodos para conversão dos caracteres para maiúsculo e minúsculo;
8. Métodos para verificar se uma cadeia é um prefixo ou sufixo;
9. Inserção de um caractere dada uma posição de inserção retornando verdadeiro em caso de sucesso;
10. Remoção de um caractere similar a inserção;
11. Busca de um caractere na cadeia retornando verdadeiro caso ele esteja presente na cadeia;
12. Substituição de um caractere, isto é, dados dois caracteres A e B, todos os caracteres A na cadeia devem ser substituídos pelo B;
13. Métodos de inserção, remoção, busca e substituição de uma **cadeia** similar às operações sobre caracteres;
14. Métodos de concatenação de um caractere ou cadeia. É opcional a sobrecarga do operador de adição;
15. Método para partição da cadeia por um caractere, isto é, a cadeia será separada num vetor de cadeias onde um caractere de controle deve ser fornecido de modo que a cadeia terá uma parte antes do caractere e outra depois do caractere de controle. Observe que a parte pode ser a cadeia vazia e essa operação deve ser aplicadas para todas as ocorrências do caractere de controle. Logo, se o caractere de controle aparece N vezes na cadeia então deve ser retornado um std::vector de N+1 posições. Por exemplo, para a cadeia "uma frase longa" e o caractere de controle ' ' deve ser retornado o vetor {"uma", "frase", "longa"}.
16. Método para partição da cadeia por outra cadeia similar a partição por caractere.

Além disso, você deve criar testes para verificar se cada método faz o que deveria fazer. Para isso, crie um arquivo de código-fonte com uma função para verificar cada um dos métodos criados incluindo os construtores (o destrutor também, caso exista). É opcional o uso de algum framework para execução de testes, por exemplos:

- https://github.com/catchorg/Catch2
- https://google.github.io/googletest/
- https://cpptest.sourceforge.io/

A lista será avaliada com peso 2 para os construtores, atributos e métodos com exceção do método de busca por cadeia e os métodos de partição que possuem peso 4. Além disso, a aplicação de modularização tem peso 4 e cada função de teste possui peso 1.

Observação: a aplicação não deve usar a classe std:string, biblioteca string.h ou similar.
