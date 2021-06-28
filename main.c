#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>
#define MAX 100
typedef struct data DATA;

struct data
{
    int dia;
    int mes;
    int ano;
};


struct artistas
{
    int cod_artista;
    char nome_verd[70];
    char nome_arti[70];
    DATA nasc;
    char banda [1];
    char nome_banda[20];
    char e_mail[50];
    char telefone[15];
    char nome_empre[70];
    char email_empre[50];
    int tipo_trab;
    int qtd_albuns;
    int qtd_musicas;
    float valor_cache;
} artistas[MAX];

struct musicas
{
    int cod_musica;
    char titulo[70];
    char letra[70];
    char melodia[70];
    int compositor;
    int cantor;
} musicas[MAX];

struct albuns
{
    int cod_album;
    char titulo[70];
    int musicas[20];
    DATA lanc;
    int copias_vend;
    int art_part;
} albuns[MAX];

void menuPrincipal();
void CadastrarArtista();
void CadastrarAlbuns();
void CadastrarMusicas();
void BuscarArtista();
void BuscarMusica();
void EditarArtista();
void EditarAlbum();
void EditarMusica();
void particaoArtista();
void quickSortArtista();
void BuscarAniversariante();
void LancamentoAlbuns();
void OrdenarPorData();
void RemoverArtista();
void RemoverArtista();
void RemoverAlbum();
void ParticaoMusica();
void quickSortMusica();
void quickSortAlbum();
void ParticaoAlbum();
void quickSortMusicaAlfabetica();
void ParticaoMusicaAlfabetica();
int buscaBinariaArtista();
int buscaBinariaMusica();
int buscaBinariaMusicaCompositor();
int opcao;
int qtd_cadastrado = 0;
int qtd_mus_cadastrada = 0;
int qtd_albuns_cadastrados = 0;
int qtd_artistas_part = 0;

int main ()
{
    setlocale(LC_ALL, "Portuguese");
    menuPrincipal();
}

void menuPrincipal()
{
    do
    {
        printf(
            "\n============= Bem vindo a Visual Studio !! ============= \n\n"
            "Escolha uma das opções abaixo: \n"
            "Tecle '1' para cadastrar um artista \n"
            "Tecle '2' para cadastrar uma música \n"
            "Tecle '3' para cadastrar um álbum \n"
            "Tecle '4' para buscar o artista \n"
            "Tecle '5' para buscar os álbuns de um artista \n"
            "Tecle '6' para editar um perfil cadastrado \n"
            "Tecle '7' para acessar o relatório dos álbuns que ainda serão lançados \n"
            "Tecle '8' para mostrar todos os aniversariantes do mês \n"
            "Tecle '9' para acessar tabela de e-mail dos empresários envolvidos \n"
            "Tecle '10' para remover um perfil cadastrado\n"
            "Tecle '0' para sair\n\n"
        );
        printf("Insira aqui sua resposta: ");
        scanf("%d", &opcao);
        system ("cls");
        switch(opcao)
        {
        case 1:
            CadastrarArtista();
            break;
        case 2:
            CadastrarMusicas();
            break;
        case 3:
            CadastrarAlbuns();
            break;
        case 4:
            BuscarArtista();
            break;
        case 6:
            EditarArtista();
            break;
        case 7:
            LancamentoAlbuns();
            break;
        case 8:
            BuscarAniversariante();
            break;
        case 9:
            break;
        case 10:
            RemoverArtista();
            break;
        case 0:
            printf("Obrigada por utilizar nosso sistema!");
        default:
            printf ("\n\t\t\tOpcao invalida!\n\n");
            fflush(stdin);
        }
    }
    while(opcao != 0);
    system("cls");
}

int buscaBinariaArtista(struct artistas a[],int cod_buscado, int comeco, int fim)
{
    int meio,achou=-1;
    meio=(comeco+fim-1)/2;
    if (comeco<=fim)
    {
        if (cod_buscado==a[meio].cod_artista)
        {
            achou=meio;
            return achou;
        }
        else if(cod_buscado<a[meio].cod_artista)
            buscaBinariaArtista(artistas,cod_buscado,comeco,meio-1);
        else
            buscaBinariaArtista(artistas,cod_buscado,meio+1,fim);
    }
    else
        return achou;
}

int buscaBinariaMusica(struct musicas m[],int cod_buscado, int comeco, int fim)
{
    int meio,achou=-1;
    meio=(comeco+fim-1)/2;
    if (comeco<=fim)
    {
        if (cod_buscado==m[meio].cod_musica)
        {
            achou=meio;
            return achou;
        }
        else if(cod_buscado<m[meio].cod_musica)
            buscaBinariaMusica(musicas,cod_buscado,comeco,meio-1);
        else
            buscaBinariaMusica(musicas,cod_buscado,meio+1,fim);
    }
    else
        return achou;
}

int buscaBinariaMusicaCompositor(struct musicas m[],int cod_buscado, int comeco, int fim)
{
    int meio,achou=-1;
    meio=(comeco+fim-1)/2;
    if (comeco<=fim)
    {
        if (cod_buscado==m[meio].compositor)
        {
            achou=meio;
            return achou;
        }
        else if(cod_buscado<m[meio].compositor)
            buscaBinariaMusicaCompositor(musicas,cod_buscado,comeco,meio-1);
        else
            buscaBinariaMusicaCompositor(musicas,cod_buscado,meio+1,fim);
    }
    else
        return achou;
}

void quickSortArtista(struct artistas a[], int count)
{
    particaoArtista(a,0,count-1);
}

void particaoArtista(struct artistas a[], int esq, int dir)
{
    int i, j;
    int pivo;
    struct artistas aux;

    i = esq;
    j = dir;
    pivo = a[(esq+dir)/2].cod_artista;

    do
    {
        while((a[i].cod_artista < pivo) && (i < dir))
            i++;
        while((a[j].cod_artista > pivo) && (j > esq))
            j--;
        if(i <= j)
        {
            aux = a[i];
            a[i] = a[j];
            a[j] = aux;
            i++;
            j--;
        }
    }
    while(i <= j);

    if(esq < j)
        particaoArtista(a, esq, j);
    if(i < dir)
        particaoArtista(a, i, dir);
}

void quickSortMusica(struct musicas m[], int cont)
{
    ParticaoMusica(m,0,cont-1);
}

void ParticaoMusica(struct musicas m[], int esq, int dir)
{
    int i, j;
    int pivo;
    struct musicas aux;

    i = esq;
    j = dir;
    pivo = m[(esq+dir)/2].cod_musica;

    do
    {
        while((m[i].cod_musica < pivo) && (i < dir))
            i++;
        while((m[j].cod_musica > pivo) && (j > esq))
            j--;
        if(i <= j)
        {
            aux = m[i];
            m[i] = m[j];
            m[j] = aux;
            i++;
            j--;
        }
    }
    while(i <= j);

    if(esq < j)
        ParticaoMusica(m, esq, j);
    if(i < dir)
        ParticaoMusica(m, i, dir);
}

void quickSortMusicaAlfabetica(struct musicas m[], int cont)
{
    ParticaoMusicaAlfabetica(m,0,cont-1);
}

void ParticaoMusicaAlfabetica(struct musicas m[], int esq, int dir)
{
    int i, j;
    char pivo[70];
    struct musicas aux;

    i = esq;
    j = dir;
    strcpy(pivo, m[(esq+dir)/2].titulo);

    do
    {
        while((strcmp(m[i].titulo, pivo)<0) && (i < dir))
            i++;
        while((strcmp(m[i].titulo, pivo)>0) && (j > esq))
            j--;
        if(i <= j)
        {
            aux = m[i];
            m[i] = m[j];
            m[j] = aux;
            i++;
            j--;
        }
    }
    while(i <= j);

    if(esq < j)
        ParticaoMusicaAlfabetica(m, esq, j);
    if(i < dir)
        ParticaoMusicaAlfabetica(m, i, dir);
}

void quickSortAlbum(struct albuns al[], int cont)
{
    ParticaoAlbum(al,0,cont-1);
}

void ParticaoAlbum(struct albuns al[], int esq, int dir)
{
    int i, j;
    int pivo;
    struct albuns aux;

    i = esq;
    j = dir;
    pivo = al[(esq+dir)/2].cod_album;

    do
    {
        while((al[i].cod_album < pivo) && (i < dir))
            i++;
        while((al[j].cod_album > pivo) && (j > esq))
            j--;
        if(i <= j)
        {
            aux = al[i];
            al[i] = al[j];
            al[j] = aux;
            i++;
            j--;
        }
    }
    while(i <= j);

    if(esq < j)
        ParticaoAlbum(al, esq, j);
    if(i < dir)
        ParticaoAlbum(al, i, dir);
}

void CadastrarArtista()
{
    int op;
    bool existe;
    do
    {
        do
        {
            existe = false;
            printf("Codigo: ");
            scanf("%d", &artistas[qtd_cadastrado].cod_artista);
            if (qtd_cadastrado == 0)
            {
                existe = false;
            }
            else
                for (int i = 0; i < qtd_cadastrado; i++)
                {
                    if (artistas[qtd_cadastrado].cod_artista == artistas[i].cod_artista)
                    {
                        printf("Esse código já existe. Digite novamente\n");
                        existe = true;
                    }
                }
        }
        while (existe == true);
        fflush(stdin);
        printf("Nome verdadeiro: ");
        gets(artistas[qtd_cadastrado].nome_verd);
        printf("Nome Artistico: ");
        gets(artistas[qtd_cadastrado].nome_arti);
        printf("Data de nacimento: (00 00 0000) ");
        scanf("%d %d %d", &artistas[qtd_cadastrado].nasc.dia, &artistas[qtd_cadastrado].nasc.mes, &artistas[qtd_cadastrado].nasc.ano);
        printf("Banda [S/N]: (Digite apenas S ou N)");
        fflush(stdin);
        gets(artistas[qtd_cadastrado].banda);
        if ((strcmp(artistas[qtd_cadastrado].banda, "S")==0) || (strcmp(artistas[qtd_cadastrado].banda, "s")==0))
        {
            printf("Nome banda: ");
            scanf("%s", artistas[qtd_cadastrado].nome_banda);
        }
        else
        {
            strcpy(artistas[qtd_cadastrado].nome_banda,  "Não");
        }
        fflush(stdin);
        printf("e-mail: ");
        gets(artistas[qtd_cadastrado].e_mail);
        printf("Telefone: ");
        gets(artistas[qtd_cadastrado].telefone);
        printf("Nome empresario: ");
        gets(artistas[qtd_cadastrado].nome_empre);
        printf("e-mail empresario: ");
        gets(artistas[qtd_cadastrado].email_empre);
        do
        {
            printf("Tipo de trabalho  \n1-Cantor \n 2-Compositor \n 3-ambos: ");
            scanf("%d", &artistas[qtd_cadastrado].tipo_trab);
            if (artistas[qtd_cadastrado].tipo_trab != 1 && artistas[qtd_cadastrado].tipo_trab != 2 && artistas[qtd_cadastrado].tipo_trab != 3)
            {
                printf("Opção invalida! Digite apenas 1, 2 ou 3\n");
            }
        }
        while (artistas[qtd_cadastrado].tipo_trab != 1 && artistas[qtd_cadastrado].tipo_trab != 2 && artistas[qtd_cadastrado].tipo_trab != 3);
        printf("Quantidade albuns lançados: ");
        scanf("%d", &artistas[qtd_cadastrado].qtd_albuns);
        printf("Quantidade de músicas compostas: ");
        scanf("%d", &artistas[qtd_cadastrado].qtd_musicas);
        printf("Valor minimo de cache: ");
        scanf("%f", &artistas[qtd_cadastrado].valor_cache);
        qtd_cadastrado++;
        printf("Deseja continuar? 1- Sim 0 - Nao ");
        scanf ("%d", &op);
    }
    while (op != 0);

}

void CadastrarMusicas()
{
    int op;
    bool existe;

    do
    {
        do
        {
            existe = false;
            printf("Codigo: ");
            scanf("%d", &musicas[qtd_mus_cadastrada].cod_musica);
            if (qtd_mus_cadastrada == 0)
            {
                existe = false;
            }
            else
                for (int i = 0; i < qtd_mus_cadastrada; i++)
                {
                    if (musicas[qtd_mus_cadastrada].cod_musica == musicas[i].cod_musica)
                    {
                        printf("Esse código já existe. Digite novamente\n");
                        existe = true;
                    }
                }
        }
        while (existe == true);
        fflush(stdin);
        printf("Titulo: ");
        gets(musicas[qtd_mus_cadastrada].titulo);
        printf("Letra (link): ");
        gets(musicas[qtd_mus_cadastrada].letra);
        printf("Melodia (link): ");
        gets(musicas[qtd_mus_cadastrada].melodia);
        printf("Código do compositor: ");
        scanf("%d", &musicas[qtd_mus_cadastrada].compositor);
        printf("Código do cantor/vocalista: ");
        scanf("%d", &musicas[qtd_mus_cadastrada].cantor);
        qtd_mus_cadastrada++;
        printf("Deseja continuar? 1- Sim 0 - Nao ");
        scanf ("%d", &op);
    }
    while (op != 0);
    quickSortArtista(artistas, qtd_cadastrado);
}

void CadastrarAlbuns()
{
    int op, i;
    bool existe;

    do
    {
        do
        {
            existe = false;
            printf("Codigo do álbum: ");
            scanf("%d", &albuns[qtd_albuns_cadastrados].cod_album);
            if (qtd_albuns_cadastrados == 0)
            {
                existe = false;
            }
            else
                for (int i = 0; i < qtd_mus_cadastrada; i++)
                {
                    if (albuns[qtd_albuns_cadastrados].cod_album == albuns[i].cod_album)
                    {
                        printf("Esse código já existe. Digite novamente\n");
                        existe = true;
                    }
                }
        }
        while (existe == true);
        fflush(stdin);
        printf("Titulo: ");
        gets(albuns[qtd_albuns_cadastrados].titulo);
        fflush(stdin);
        printf("Lista de Canções (Código separado por espaço): ");
        scanf("%d", &albuns[qtd_albuns_cadastrados].musicas);
        fflush(stdin);
        printf("Data lançamento (00 00 0000): ");
        scanf("%d %d %d", &albuns[qtd_albuns_cadastrados].lanc.dia, &albuns[qtd_albuns_cadastrados].lanc.mes, &albuns[qtd_albuns_cadastrados].lanc.ano);
        fflush(stdin);
        printf("Numero de copias vendidas: ");
        scanf("%d", &albuns[qtd_albuns_cadastrados].copias_vend);
        fflush(stdin);
        printf("Quantos artistas participam? ");
        scanf("%d", &qtd_artistas_part);
        for (i = 0; i < qtd_artistas_part; i++){
            printf("Artistas Participante %d°: ", i);
            scanf("%d", albuns[qtd_albuns_cadastrados].art_part);
        }
        qtd_albuns_cadastrados++;
        printf("Deseja continuar? 1- Sim 0 - Nao ");
        scanf ("%d", &op);
    }
    while (op != 0);
}

void BuscarArtista()
{
    int c = 0, busca;
    int j = 0;
    int i = 0;
    quickSortArtista(artistas, qtd_cadastrado);
    for (c = 0; c < qtd_cadastrado; c++)
    {
        printf("\n %d --- %s", artistas[c].cod_artista, artistas[c].nome_arti);
    }
    printf("\nDigite o codigo que você quer buscar: ");
    scanf("%d", &busca);
    j = buscaBinariaArtista(artistas,busca,0,qtd_albuns_cadastrados);
    if (j != -1)
    {
        printf("\n Codigo: %d", artistas[j].cod_artista );
        printf("\n Nome verdadeiro: %s ", artistas[j].nome_verd);
        printf("\n Nome Artistico: %s", artistas[j].nome_arti);
        printf("\n Data de nacimento: %d/%d/%d", artistas[j].nasc.dia, artistas[j].nasc.mes, artistas[j].nasc.ano);
        printf("\n Banda [S/N]: %s", artistas[j].banda);
        printf("\n Nome banda: %s ", artistas[j].nome_banda);
        printf("\n e-mail: %s", artistas[j].e_mail );
        printf("\n Telefone: %s ", artistas[j].telefone);
        printf("\n Nome empresario: %s ", artistas[j].nome_empre);
        printf("\n e-mail empresario: %s", artistas[j].email_empre);
        printf("\n Tipo de trabalho: %d ", artistas[j].tipo_trab);
        printf("\n Quantidade albuns lançados: %d", artistas[j].qtd_albuns );
        printf("\n Quantidade de músicas compostas: %d ", artistas[j].qtd_musicas);
        printf("\n Valor minimo de cache: R$ %.2f ", artistas[j].valor_cache);
        printf("\n");
    }
    quickSortMusicaAlfabetica(musicas, qtd_mus_cadastrada);
    printf("\n**************************************************");
    printf("\n                   MUSICAS                        ");
    printf("\n**************************************************");
    for (i = 0; i < qtd_mus_cadastrada; i++)
        if (busca == musicas[i].compositor){
            printf("\nCodigo: %d ", musicas[i].cod_musica);
            printf("\nTitulo: %s ", musicas[i].titulo);
            printf("\n");
        }

}

void BuscarMusica()
{
    int c = 0, busca;
    int j = 0;
    quickSortMusica(musicas, qtd_mus_cadastrada);
    for (c = 0; c < qtd_mus_cadastrada; c++)
    {
        printf("\n %d ------ %s", artistas[c].cod_artista, artistas[c].nome_arti);
    }
    printf("\nDigite o codigo da música que você quer buscar: ");
    scanf("%d", &busca);
    j = buscaBinariaMusica(musicas,busca,0,qtd_mus_cadastrada);
    if (j != -1)
    {
        printf("Codigo: %d ", musicas[j].cod_musica);
        printf("Titulo: %s ", musicas[j].titulo);
        printf("Letra (link): %s", musicas[j].letra);
        printf("Melodia (link): %s", musicas[j].melodia);
        printf("Código do compositor: %d", musicas[j].compositor);
        printf("Código do cantor/vocalista: %d ", musicas[j].cantor);
    }
}

void EditarArtista()
{
    int cod_busca, op, c;
    printf("Digite o código do artista que quer editar: ");
    scanf("%d", &cod_busca);
    for (c = 0; c < qtd_cadastrado; c++)
    {
        if (cod_busca == artistas[c].cod_artista)
        {
            printf(
                "\n============= Opções ============= \n\n"
                "Escolha uma das opções abaixo: \n"
                "Tecle '1' para editar o nome verdadeiro do artista\n"
                "Tecle '2' para editar o nome artistico \n"
                "Tecle '3' para editar a data de nascimento \n"
                "Tecle '4' para editar o nome da banda \n"
                "Tecle '5' para editar o e-mail \n"
                "Tecle '6' para editar o telefone \n"
                "Tecle '7' para editar o nome do empresario \n"
                "Tecle '8' para editar o e-mail do empresario \n"
                "Tecle '9' para editar o tipo de trabalho \n"
                "Tecle '10' para editar a quantidade albuns lançados\n"
                "Tecle '11' para editar a quantidade de musicas compostas\n"
                "Tecle '12' para editar o valor minimo do cache\n"
                "Tecle '0' para sair\n\n"
            );
            scanf("%d", &op);
            switch(op)
            {
            case 1:
                fflush(stdin);
                printf("Nome verdadeiro: ");
                gets(artistas[c].nome_verd);
                break;
            case 2:
                fflush(stdin);
                printf("Nome Artistico: ");
                gets( artistas[c].nome_arti);
                break;
            case 3:
                fflush(stdin);
                printf("Data de nacimento: ");
                scanf("%d %d %d", &artistas[c].nasc.dia, &artistas[c].nasc.mes, &artistas[c].nasc.ano);
                break;
            case 4:
                fflush(stdin);
                printf("Nome banda: ");
                gets( artistas[c].nome_banda);
                break;
            case 5:
                fflush(stdin);
                printf("e-mail: ");
                gets(artistas[c].e_mail);
                break;
            case 6:
                fflush(stdin);
                printf("Telefone: ");
                gets(artistas[c].telefone);
                break;
            case 7:
                fflush(stdin);
                printf("Nome empresario: ");
                gets(artistas[c].nome_empre);
                break;
            case 8:
                printf("e-mail empresario: ");
                gets(artistas[c].email_empre);
                break;
            case 9:
                printf("Tipo de trabalho  \n1-Cantor \n 2-Compositor \n 3-ambos\n: ");
                scanf("%d", &artistas[c].tipo_trab);
                break;
            case 10:
                printf("Quantidade albuns lançados: ");
                scanf("%d", &artistas[c].qtd_albuns);
                break;
            case 11:
                printf("Quantidade de músicas compostas: ");
                scanf("%d", &artistas[c].qtd_musicas);
                break;
            case 12:
                printf("Valor minimo de cache: ");
                scanf("%f", &artistas[c].valor_cache);
                break;
            case 0:
                printf("Saindo...");
                printf ("\n\t\t\tOpcao invalida!\n\n");
                fflush(stdin);
            }
        }
        else
            printf("Código não encontrado");
    }
}

void EditarMusica()
{
    int cod_busca, op, c;
    printf("Digite o código da musica que quer editar: ");
    scanf("%d", &cod_busca);
    for (c = 0; c < qtd_mus_cadastrada; c++)
    {
        if (cod_busca == musicas[c].cod_musica)
        {
            printf(
                "\n============= Opções ============= \n\n"
                "Escolha uma das opções abaixo: \n"
                "Tecle '1' para editar o titulo\n"
                "Tecle '2' para editar a letra \n"
                "Tecle '3' para editar a melodia \n"
                "Tecle '4' para editar o compositor \n"
                "Tecle '5' para editar o vocalista/cantor \n"
                "Tecle '0' para sair\n\n"
            );
            scanf("%d", &op);
            switch(op)
            {
            case 1:
                fflush(stdin);
                printf("Titulo: ");
                gets( musicas[c].titulo);
                break;
            case 2:
                fflush(stdin);
                printf("Letra: ");
                gets( musicas[c].letra);
                break;
            case 3:
                fflush(stdin);
                printf("Melodia: ");
                gets(musicas[c].melodia);
                break;
            case 4:
                printf("Compositor: ");
                scanf("%d", &musicas[c].compositor);
                break;
            case 5:
                printf("Cantor/Vocalista: ");
                scanf("%d", &musicas[c].cantor);
                break;
            case 0:
                printf("Edição Finalizada");
            default:
                printf ("\n\t\t\tOpcao invalida!\n\n");
                fflush(stdin);
            }
        }
        else
            printf("Código não encontrado");
    }
}

void EditarAlbum()
{
    int cod_busca, op, c;
    printf("Digite o código do album que quer editar: ");
    scanf("%d", &cod_busca);
    for (c = 0; c < qtd_albuns_cadastrados; c++)
    {
        if (cod_busca == albuns[c].cod_album)
        {
            printf(
                "\n============= Opções ============= \n\n"
                "Escolha uma das opções abaixo: \n"
                "Tecle '1' para editar o titulo\n"
                "Tecle '2' para editar a lista de musicas \n"
                "Tecle '3' para editar a data do lançamento\n"
                "Tecle '4' para editar o numero de copias vendidas\n"
                "Tecle '5' para editar os artistas participantes \n"
                "Tecle '0' para sair\n\n"
            );
            scanf("%d", &op);
            switch(op)
            {
            case 1:
                fflush(stdin);
                printf("Titulo: ");
                gets(albuns[c].titulo);
                break;
            case 2:
                fflush(stdin);
                printf("Lista de musicas: ");
                scanf("%d", albuns[c].musicas);
                break;
            case 3:
                fflush(stdin);
                printf("Data lançamento (00 00 0000): ");
                scanf("%d %d %d", &albuns[c].lanc.dia, &albuns[c].lanc.mes, &albuns[c].lanc.ano);
                break;
            case 4:
                printf("Numero de copias vendidas: ");
                scanf("%d", &albuns[c].copias_vend);
                break;
            case 5:
                printf("Listas de artistas participantes: ");
                scanf("%d", &albuns[c].art_part);
                break;
            case 0:
                printf("Edição Finalizada");
            default:
                printf ("\n\t\t\tOpcao invalida!\n\n");
                fflush(stdin);
            }
        }
        else
            printf("Código não encontrado");
    }
}

void BuscarAniversariante()
{
    int busca;
    printf("Você quer buscar aniversariante de qual mês? (Apenas numerico) ");
    scanf("%d", &busca);
    for (int i = 0; i <qtd_artistas_part; i++)
    {
        if (busca == artistas[i].nasc.mes)
        {
            printf("\n Codigo: %d", artistas[i].cod_artista );
            printf("\n Nome Artistico: %s", artistas[i].nome_arti);
            printf("\n Data de nacimento: %d/%d/%d", artistas[i].nasc.dia, artistas[i].nasc.mes, artistas[i].nasc.ano);
            printf("\n Valor do cache no mes do seu aniversário com acrescismo de 20%: R$ %.2f ", (artistas[i].valor_cache) + (artistas[i].valor_cache * 0.2));
            printf("");
        }
    }
}

void LancamentoAlbuns()
{
    int busca;
    printf("Você quer buscar qual ano de lançamento dos albuns? (Apenas numerico) ");
    scanf("%d", &busca);
    OrdenarPorData();
    for (int i = 0; i <qtd_albuns_cadastrados; i++)
    {
        if (busca == albuns[i].lanc.ano)
        {
            printf("\n Codigo: %d", albuns[i].cod_album );
            printf("\n Titulo: %s", albuns[i].titulo);
            printf("\n Data de Lançamento: %d/%d/%d", albuns[i].lanc.dia, albuns[i].lanc.mes, albuns[i].lanc.ano);
            printf("");
        }
    }
}

void OrdenarPorData()
{
    int j, i;
    struct albuns aux;
    //oraganizando ano
    for (i = 0; i < qtd_albuns_cadastrados; i++)
        for (j = i+1; j <qtd_albuns_cadastrados; j ++)
        {
            if (albuns[i].lanc.ano>= albuns[j].lanc.ano)
            {
                aux = albuns[i];
                albuns[i] = albuns[j];
                albuns[j] = aux;
            }
        }
    //organizando mes
    for (i = 0; i < qtd_albuns_cadastrados; i++)
        for (j = i+1; j < qtd_albuns_cadastrados; j ++)
        {
            if (albuns[i].lanc.ano == albuns[j].lanc.ano)
            {
                if (albuns[i].lanc.mes > albuns[j].lanc.mes)
                {
                    aux = albuns[i];
                    albuns[i] = albuns[j];
                    albuns[j] = aux;
                }
            }
        }
    //organizando dia
    for (i = 0; i < qtd_albuns_cadastrados; i++)
        for (j = i+1; j <qtd_albuns_cadastrados; j ++)
        {
            if (albuns[i].lanc.ano == albuns[j].lanc.ano && albuns[i].lanc.mes == albuns[j].lanc.mes)
            {
                if (albuns[i].lanc.dia > albuns[j].lanc.dia)
                {
                    aux = albuns[i];
                    albuns[i] = albuns[j];
                    albuns[j] = aux;
                }
            }
        }
    //**for (j = 0; j < qtd_albuns_cadastrados; j++){
    //printf("\n Codigo: %d", albuns[j].cod_album );
    //printf("\n Data de Lançamento: %d/%d/%d", albuns[j].lanc.dia, albuns[j].lanc.mes, albuns[j].lanc.ano);
    //printf("");}
}

void RemoverArtista()
{
    int busca_cod, i, pos;
    printf("Você quer remover qual cadastro de artista?(Código)?");
    scanf("%d", &busca_cod);

    for (i = 0; i < qtd_cadastrado; i++){
        if (busca_cod == artistas[i].cod_artista){
            pos = i;
        }
    }
    for (i = pos;i < qtd_cadastrado - 1; i++){
        artistas[i] = artistas[i + 1];
        }
    qtd_cadastrado--;
}

void RemoverMusica()
{
    int busca_cod, i, pos;
    printf("Você quer remover qual cadastro de musica?(Código)?");
    scanf("%d", &busca_cod);

    for (i = 0; i < qtd_mus_cadastrada; i++){
        if (busca_cod == musicas[i].cod_musica){
            pos = i;
        }
    }
    for (i = pos;i < qtd_mus_cadastrada - 1; i++){
        musicas[i] = musicas[i + 1];
        }
    qtd_mus_cadastrada--;
}

void RemoverAlbum()
{
    int busca_cod, i, pos;
    printf("Você quer remover qual cadastro de album?(Código)?");
    scanf("%d", &busca_cod);

    for (i = 0; i < qtd_albuns_cadastrados; i++){
        if (busca_cod == albuns[i].cod_album){
            pos = i;
        }
    }
    for (i = pos;i < qtd_albuns_cadastrados - 1; i++){
        albuns[i] = albuns[i + 1];
        }
    qtd_albuns_cadastrados--;
}
