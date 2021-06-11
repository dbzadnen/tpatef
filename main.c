#include<stdio.h>>
#include<stdlib>
#include<string.h>

//definitions :
typedef struct article ARTICLE;
typedef struct famille FAMILLE;
typedef struct fournisseur FOURNISSEUR;
typedef struct procede PROCEDE;
typedef struct list_article LIST_ARTICLE;
typedef struct list_famille LIST_FAMILLE;
typedef struct list_fournisseur LIST_FOURNISSEUR;
typedef struct arbre_procede ARBRE_PROCEDE;

//declarations:
struct article{
     int code;
     char[15] designation;
     float prix_achat;
     int code_fournisseur;
     int quantite_en_stock;
};
struct famille{
     int code;
     char[15] designation;
};
struct fournisseur{
     int code;
     char[15] raison_social;
};
struct procede{
    int code_compose;
    int code_composant;
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
//API Fournisseur :
FOURNISSEUR*  creerFournisseur (int code , char[] raison_social){
    FOURNISSEUR* f = (FOURNISSEUR*)malloc(sizeof(FOURNISSEUR*));
    f->code = code;
    f->raison_social =raison_social;
    return f;
}
LIST_FOURNISSEUR* creerListFournisseur(FOURNISSEUR fournisseur){
    LIST_FOURNISSEUR* lf = (LIST_FOURNISSEUR*) malloc(sizeof(LIST_FOURNISSEUR));
    lf->next = null;
    lf->data = fournisseur;
    return lf;
}
void insereListFournisseur(LIST_FOURNISSEUR** lf,FOURNISSEUR f){
    LIST_FOURNISSEUR* temp = creerListFournisseur(f);
    temp->next = *lf;
    *lf = temp;
}
// API article 
ARTICLE* creerArticle (int code , char[] deisgnation,float prix_achat,int code_fournisseur,int quantite_en_stock){
    ARTICLE* f = (ARTICLE*)malloc(sizeof(ARTICLE*));
    f->code = code;
    f->deisgnation =deisgnation;
    f->prix_achat =prix_achat;
    f->code_fournisseur =code_fournisseur;
    f->quantite_en_stock =quantite_en_stock;
    return f;
}

LIST_ARTICLE* creerListArticle(ARTICLE article){
    LIST_ARTICLE* la = (LIST_ARTICLE*) malloc(sizeof(LIST_ARTICLE));
    lf->next = null;
    lf->data = article;
    return la;
}
void insereListArticle(LIST_ARTICLE** la,ARTICLE a){
    LIST_ARTICLE* temp = creerListArticle(a);
    temp->next = *la;
    *la = temp;
}
// API famille 
FAMILLE*  creerFamille (int code , char[] raison_social){
    FAMILLE* f = (FAMILLE*)malloc(sizeof(FAMILLE*));
    f->code = code;
    f->raison_social =raison_social;
    return f;
}

LIST_FAMILLE* creerListFamille(FAMILLE famille){
    LIST_FAMILLE* lf = (LIST_FAMILLE*) malloc(sizeof(LIST_FAMILLE));
    lf->next = null;
    lf->data = famille;
    return lf;
}
void insereListFamille(LIST_FAMILLE** lf,FAMILLE f){
    LIST_FAMILLE* temp = creerListFamille(f);
    temp->next = *lf;
    *lf = temp;
}