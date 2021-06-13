#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//definitions :
typedef struct article ARTICLE;
typedef struct famille FAMILLE;
typedef struct fournisseur FOURNISSEUR;
typedef struct procede PROCEDE;
typedef struct list_article LIST_ARTICLE;
typedef struct list_famille LIST_FAMILLE;
typedef struct list_fournisseur LIST_FOURNISSEUR;
typedef struct list_procede LIST_PROCEDE;
typedef struct arbre_procede ARBRE_PROCEDE;

//declarations:
struct article{
     int code;
     char designation[15];
     char code_famille[5];
     float prix_achat;
     int code_fournisseur;
     int quantite_en_stock;
};
struct famille{
     int code;
     char designation[15] ;
};
struct fournisseur{
     int code;
     char raison_social[15] ;
};
struct procede{
    int code;
    int parent;
    int quantite;
};
struct list_article{
    ARTICLE data;
    LIST_ARTICLE* next;
};
struct list_famille{
    FAMILLE data;
    LIST_FAMILLE* next;
};
struct list_fournisseur{
    FOURNISSEUR data;
    LIST_FOURNISSEUR* next;
};
struct list_procede{
    PROCEDE d;
    LIST_PROCEDE* next;
};
struct arbre_procede{
    PROCEDE d;
    ARBRE_PROCEDE* fils;
    ARBRE_PROCEDE* frere;
};
//API Fournisseur :
/*FOURNISSEUR* creerFournisseur(int code , char raison_social[]){
    FOURNISSEUR* f = (FOURNISSEUR*)malloc(sizeof(FOURNISSEUR*));
    f->code = code;
    strcpy(f->raison_social,raison_social);
    return f;
}*/
LIST_FOURNISSEUR* creerListFournisseur(FOURNISSEUR fournisseur){
    LIST_FOURNISSEUR* lf = (LIST_FOURNISSEUR*) malloc(sizeof(LIST_FOURNISSEUR));
    lf->next = NULL;
    lf->data = fournisseur;
    return lf;
}
void insereListFournisseur(LIST_FOURNISSEUR** lf,FOURNISSEUR f){
    LIST_FOURNISSEUR* temp = creerListFournisseur(f);
    temp->next = *lf;
    *lf = temp;
}
void loadListFournisseur(char* inputs,LIST_FOURNISSEUR** liste_des_fournisseurs ){
    FOURNISSEUR f;
    sscanf(inputs,"%5d%15s",&f.code,&f.raison_social);
    insereListFournisseur(liste_des_fournisseurs,f);
}
void loadAllFournisseur(char* file_name,LIST_FOURNISSEUR** liste_des_fournisseurs ){
    FILE* fp = fopen(file_name,"r");
    char ligne[100];
    while(fgets(ligne,100,fp)){
        loadListFournisseur(ligne,liste_des_fournisseurs);
    }
    fclose(fp);
}
void viewListFourniseur(LIST_FOURNISSEUR* ls){
    if(ls){
        printf("%d",ls->data.code);
        viewListFourniseur(ls->next);
    }
}
void freeListFournisseur(LIST_FOURNISSEUR* f){
    if(f){
        freeListFournisseur(f->next);
        free(f);
    }
}
// API article 
/*ARTICLE* creerArticle (int code , char designation[] , char code_famille[] ,float prix_achat,int code_fournisseur,int quantite_en_stock){
    ARTICLE* f = (ARTICLE*)malloc(sizeof(ARTICLE*));
    f->code = code;
    strcpy(f->designation, designation);
    f->prix_achat =prix_achat;
    strcpy(f->code_famille,code_famille);
    f->code_fournisseur =code_fournisseur;
    f->quantite_en_stock =quantite_en_stock;
    return f;
}*/
LIST_ARTICLE* creerListArticle(ARTICLE article){
    LIST_ARTICLE* la = (LIST_ARTICLE*) malloc(sizeof(LIST_ARTICLE));
    la->next = NULL;
    la->data = article;
    return la;
}
void insereListArticle(LIST_ARTICLE** la,ARTICLE a){
    LIST_ARTICLE* temp = creerListArticle(a);
    temp->next = *la;
    *la = temp;
}
void viewListArticle(LIST_ARTICLE* ls){
    if(ls){
        printf("%d",ls->data.code);
        viewListArticle(ls->next);
    }
}
void loadListArticle(char* inputs,LIST_ARTICLE** liste_des_articles ){
    ARTICLE a ;
    sscanf(inputs,"%5d%15s%5s%10f%5d%5d",&a.code,&a.designation,&a.code_famille,&a.prix_achat,&a.code_fournisseur,&a.quantite_en_stock);
    insereListArticle(liste_des_articles,a);
}
void loadAllArticle(char* file_name,LIST_ARTICLE** liste_des_articles ){
    FILE* fp = fopen(file_name,"r");
    char ligne[100];
    while(fgets(ligne,100,fp)){
        //printf("%s",ligne);
        loadListArticle(ligne,liste_des_articles);
    }
    fclose(fp);
}
void freeListArticle(LIST_ARTICLE* f){
    if(f){
        freeListArticle(f->next);
        free(f);
    }
}
LIST_ARTICLE* findListArticle(LIST_ARTICLE* ls,int code){
    if(ls){
        if(ls->data.code == code)
            return ls;
        return findListArticle(ls->next,code);
    }
    return NULL;
}
// API famille 
/*FAMILLE*  creerFamille (int code , char designation[]){
    FAMILLE* f = (FAMILLE*)malloc(sizeof(FAMILLE*));
    f->code = code;
    strcpy(f->designation,designation);
    return f;
}*/
LIST_FAMILLE* creerListFamille(FAMILLE famille){
    LIST_FAMILLE* lf = (LIST_FAMILLE*) malloc(sizeof(LIST_FAMILLE));
    lf->next = NULL;
    lf->data = famille;
    return lf;
}
void insereListFamille(LIST_FAMILLE** lf,FAMILLE f){
    LIST_FAMILLE* temp = creerListFamille(f);
    temp->next = *lf;
    *lf = temp;
}
void loadListFamille(char* inputs,LIST_FAMILLE** liste_des_familles ){
    FAMILLE f ;
    sscanf(inputs,"%5d%15s",&f.code,&f.designation);
    insereListFamille(liste_des_familles,f);
}
void loadAllFamille(char* file_name,LIST_FAMILLE** liste_des_familles ){
    FILE* fp = fopen(file_name,"r");
    char ligne[100];
    while(fgets(ligne,100,fp)){
        loadListFamille(ligne,liste_des_familles);
    }
    fclose(fp);
}
void viewListFamille(LIST_FAMILLE* ls){
    if(ls){
        printf("%d",ls->data.code);
        viewListFamille(ls->next);
    }
}
void freeListFamille(LIST_FAMILLE* f){
    if(f){
        freeListFamille(f->next);
        free(f);
    }
}

//API procede :
    //API Arbre
ARBRE_PROCEDE* creerArbreProcede (PROCEDE p){
    ARBRE_PROCEDE* a = (ARBRE_PROCEDE*) malloc(sizeof(ARBRE_PROCEDE));
    a->d = p;
    a->fils = NULL;
    a->frere = NULL;
    return a;
}
void insereArbreProcede(PROCEDE p ,ARBRE_PROCEDE** racine){
   if(*racine){
       if((*racine)->d.code == p.parent){
           ARBRE_PROCEDE* nouveaux = creerArbreProcede(p);
           nouveaux->frere = (*racine)->fils;
           (*racine)->fils = nouveaux;      
       } 
        insereArbreProcede(p,&(*racine)->fils);
        insereArbreProcede(p,&(*racine)->frere);
   }
}
void insereRacineArbreProcede(PROCEDE p ,ARBRE_PROCEDE** racine){
   ARBRE_PROCEDE* nouveaux = creerArbreProcede(p);
   nouveaux->d.quantite = 1;
   nouveaux->d.code = nouveaux->d.parent;
   nouveaux->d.parent = -1;
   nouveaux->frere = (*racine);
   (*racine) = nouveaux;      
}
ARBRE_PROCEDE* seekArbreProcede(ARBRE_PROCEDE* racine,int cle){
    if(racine){
        if(racine->d.code == cle)
            return racine;
        ARBRE_PROCEDE* ar = seekArbreProcede(racine->fils,cle);
        if(!ar)
        return seekArbreProcede(racine->frere,cle);
        else
        return ar;
    }
    return NULL;
}
void loadProcede(char* inputs,ARBRE_PROCEDE** racine){
    PROCEDE d;
    sscanf(inputs,"%5d%5d%5d",&d.parent,&d.code,&d.quantite);
    if(!seekArbreProcede(*racine,d.parent)){
        insereRacineArbreProcede(d,racine);
    }
    insereArbreProcede(d,racine);
}
void construireArbreProcede(char* file_name ,ARBRE_PROCEDE** racine){
    FILE* fp = fopen(file_name,"r");
    char ligne[100];
    while(fgets(ligne,100,fp)){
        loadProcede(ligne,racine);
    }
    fclose(fp);
}
void freeArbreProcede(ARBRE_PROCEDE* racine){
    if(racine){
    freeArbreProcede(racine->frere);
    freeArbreProcede(racine->fils);
    free(racine);
    racine = NULL;
    }

}
void viewArbreProcede(ARBRE_PROCEDE* racine){
    if(racine){
        printf(" --  %d est fils de %d  -- \n ",racine->d.code,racine->d.parent);
        viewArbreProcede(racine->fils);
        viewArbreProcede(racine->frere);
    }
}

    //API list procede : 
LIST_PROCEDE* creerListProcede(PROCEDE p){
    LIST_PROCEDE* lf = (LIST_PROCEDE*) malloc(sizeof(LIST_PROCEDE));
    lf->next = NULL;
    lf->d = p;
    return lf;
}
void insereListProcede(LIST_PROCEDE** lf,PROCEDE f){
    LIST_PROCEDE* temp = creerListProcede(f);
    temp->next = *lf;
    *lf = temp;
}
void viewListProcede(LIST_PROCEDE* ls){
    if(ls){
        printf(" -- id : %d - quantite : %d  -- \n",ls->d.code,ls->d.quantite);
        viewListProcede(ls->next);
    }
}
LIST_PROCEDE* findListProcede(LIST_PROCEDE* ls,int code){
    if(ls){
        if(ls->d.code == code)
            return ls;
        return findListProcede(ls->next,code);
    }
    return NULL;
}
void freeListProcede(LIST_PROCEDE* f){
    if(f){
        freeListProcede(f->next);
        free(f);
    }
}
//Problem Functions :
void besoinEnProduit(ARBRE_PROCEDE* racine,LIST_PROCEDE** ls,int quantite){
    if(racine){
        besoinEnProduit(racine->frere,ls,quantite);
        quantite = quantite * racine->d.quantite;
        besoinEnProduit(racine->fils,ls,quantite);
        if(!racine->fils){
            LIST_PROCEDE* item = findListProcede(*ls,racine->d.code);
            if(item){
                item->d.quantite=  item->d.quantite + quantite;
            }else{
                PROCEDE mp = racine->d;
                mp.quantite = quantite;
                insereListProcede(ls,mp);
            }
        }
    }
}
int findMpEtPrix(ARBRE_PROCEDE* racine,LIST_ARTICLE* articles,int code){
    ARBRE_PROCEDE* produit = seekArbreProcede(racine,code);
    if(produit){
        printf("------------Produit : %d\n",produit->d.code);
        LIST_PROCEDE* ls = NULL;
        besoinEnProduit(produit->fils,&ls,produit->d.quantite);
        LIST_PROCEDE* iterator = ls;
        float prixTotal = 0;
        for(iterator;iterator;iterator = iterator->next){
            printf("Code Matiere Premiere : %d ---- Quantite : %d \n",iterator->d.code,iterator->d.quantite);
            prixTotal =  prixTotal +  findListArticle(articles,iterator->d.code)->data.prix_achat * (iterator->d.quantite);
        }
        printf("\n------------ COUT MATIERE : %f ------------\n \n ",prixTotal);
        freeListProcede(ls);
        ls = NULL;
        return 1;
    }
    return 0;
}
void showPfCout(ARBRE_PROCEDE* racine,LIST_ARTICLE* articles){
    printf("\nTous les PF :\n");
    while(racine){
        LIST_ARTICLE* current = findListArticle(articles,racine->d.code);
        printf("\nProduit Final : %s , Details : \n",current->data.designation);
        findMpEtPrix(racine,articles,racine->d.code);
        racine = racine->frere;
    }
    printf("--------------FIN\n");

}
void showFournisseurProduction(LIST_FOURNISSEUR* lf,ARBRE_PROCEDE* racine,LIST_ARTICLE* la){
    printf("-------Details Fournisseur : \n");
    for(lf;lf;lf=lf->next){
        ARBRE_PROCEDE* iterator = racine;
        int total = 0;
        for(iterator;iterator;iterator=iterator->frere){
            int found = 0;
            LIST_PROCEDE* ls = NULL,*copy = NULL;
            besoinEnProduit(iterator->fils,&ls,iterator->d.quantite);
            for(copy = ls;ls && !found;ls = ls->next){
                found = (findListArticle(la,ls->d.code)->data.code_fournisseur == lf->data.code)? 1 : 0;
            }
            total+= found;
            freeListProcede(copy);
        }
        printf("Code Fournisseur : %d , Nombre De Participations Dans Les PF : %d \n",lf->data.code,total);
    }
    printf("-------FIN Details Fournisseur : \n");
}
void programmeDeProduction(ARBRE_PROCEDE* arbre,LIST_ARTICLE* ls ){
    int produit,quantite;
    LIST_PROCEDE* besoin = NULL;
    do{
        printf("Produit et besoin en quantite :\n");
        scanf("%d %d",&produit,&quantite);
        if(produit && quantite)
        besoinEnProduit(seekArbreProcede(arbre,produit)->fils,&besoin,quantite);
    }while(produit || quantite);
    printf("------------Programme De Production :\n");
    printf("Matiere     Besoin     Stock     Manquant\n");
    int faisable = 0;
    for(besoin;besoin;besoin = besoin->next){
        int stock = findListArticle(ls,besoin->d.code)->data.quantite_en_stock;
        int manquant = besoin->d.quantite - stock;
        printf("%8d %8d %8d ",besoin->d.code,besoin->d.quantite,stock);
        manquant = manquant <0 ? 0 : manquant;
        printf("%8d\n",manquant);
        faisable+= manquant;
    }
    freeListProcede(besoin);printf("Programme De Production Est ");
    if(faisable) 
        printf("Non ");
    printf("Faisable\n");
    printf("------------FIN Programme De Production :\n");
}
//DATA reading
void loadFiles(ARBRE_PROCEDE** racine,LIST_FAMILLE** liste_des_familles,LIST_FOURNISSEUR** liste_des_fournisseurs, LIST_ARTICLE** liste_des_articles ,char* article_txt,char* famille_txt,char* fournisseur_txt,char* procede_txt){
    loadAllFamille(famille_txt,liste_des_familles);
    loadAllFournisseur(fournisseur_txt,liste_des_fournisseurs);
    loadAllArticle(article_txt,liste_des_articles);
    construireArbreProcede(procede_txt,racine);
}
//Utility
void freeMemory(ARBRE_PROCEDE* racine,LIST_FAMILLE* liste_des_familles,LIST_FOURNISSEUR*liste_des_fournisseurs, LIST_ARTICLE* liste_des_articles){
    freeArbreProcede(racine);
    freeListArticle(liste_des_articles);
    freeListFamille(liste_des_familles);
    freeListFournisseur(liste_des_fournisseurs);
    racine = NULL;liste_des_articles=NULL;liste_des_familles = NULL;liste_des_fournisseurs = NULL;
}
//MAIN
void main(){
    ARBRE_PROCEDE* arbre= NULL;
    LIST_FAMILLE* liste_des_familles = NULL;
    LIST_FOURNISSEUR* liste_des_fournisseurs = NULL;
    LIST_ARTICLE* liste_des_articles = NULL;
   // LIST_PROCEDE* matiere_premieres = NULL;
   loadFiles(&arbre,&liste_des_familles,&liste_des_fournisseurs,&liste_des_articles,"Article.txt","Famille.txt","Fournisseur.txt","Procede.txt");
   int choix = -1,code = -1;
   do{
    printf("\n ****************** MENU ******************\n");
    printf("Choix 1 : Composition et cout d'un article\n");
    printf("Choix 2 : Resume de la composition des produits finis\n");
    printf("Choix 3 : Resume sur les Fournisseur concerant les produits finis\n");
    printf("Choix 4 : Programme de production\n");
    printf("Choix 0 : Terminer le programme\n");
    scanf("%d",&choix);
    switch (choix)
    {
        case 1:
            printf("Donnez le code de l'article desirer :\n");
            scanf("%d",&code);
            findMpEtPrix(arbre,liste_des_articles,code);
            break;
        case 2:
            showPfCout(arbre,liste_des_articles);
            break;
        case 3:
            showFournisseurProduction(liste_des_fournisseurs,arbre,liste_des_articles);
            break;
        case 4:
            programmeDeProduction(arbre,liste_des_articles);
            break;
        default:
            if(choix)
                printf("----- Choix Non Valide , Entrez un numero entre 1 et 4 inclusive \n");
            break;
    }
   }while(choix);
   freeMemory(arbre,liste_des_familles,liste_des_fournisseurs,liste_des_articles);
}