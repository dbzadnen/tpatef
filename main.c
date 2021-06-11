#include<stdio.h>
#include<stdlib.h>

void loadListArticle(char* inputs,LIST_ARTICLE** liste_des_articles ){
    ARTICLE a ;
    sscanf(inputs,"%5d%15s%5s%10ld%5d%5d",a.code,a.designation,a.code_famille,a.prix_achat,a.code_fournisseur,a.quantite_en_stock);
    insereListArticle(liste_des_articles,a);
}
void loadAllArticle(char* file_name,LIST_ARTICLE** liste_des_articles ){
    FILE* fp = fopen(file_name,"r");
    char ligne[100];
    while(fgets(ligne,100,fp)){
        loadListArticle(ligne,liste_des_articles);
    }
    fclose(fp);
}

void loadListFournisseur(char* inputs,LIST_FOURNISSEUR** liste_des_fournisseurs ){
    FOURNISSEUR f;
    sscanf(inputs,"%5d%15s",f.code,f.raison_social);
    insereListFournisseur(liste_des_fournisseurs,f);
}
void loadAllFournisseur(char* file_name,LIST_FOURNISSEUR** liste_des_fournisseurs ){
    FILE* fp = fopen(file_name,"r");
    char ligne[100];
    while(fgets(ligne,100,fp)){
        loadListFrounisseur(ligne,liste_des_fournisseurs);
    }
    fclose(fp);
}

void loadListFamille(char* inputs,LIST_FAMILLE** liste_des_familles ){
    FAMILLE f ;
    sscanf(inputs,"%5d%15s",f.code,f.designation);
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

void loadFiles(ARBRE_PROCEDE** composition,LIST_FAMILLE** liste_des_familles,LIST_FOURNISSEUR** liste_des_fournisseurs, LIST_ARTICLE** liste_des_articles ,char* article_txt,char* famille_txt,char* fournisseur_txt,char* procede_txt){
    loadAllFamille(famille_txt,liste_des_familles);
    loadAllFournisseur(fournisseur_txt,liste_des_fournisseurs);
    loadAllArticle(article_txt,liste_des_articles);
    construireArbre(procede_txt,composition);
}