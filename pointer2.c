#include <stdio.h>

void note_hinzufuegen(int noten[], int *panzahl);

void noten_anzeigen(int noten[], int anzahl);

float durchschnitt(int noten[], int anzahl);

int beste_note(int noten[], int anzahl);

int schlechteste_note(int noten[], int anzahl);

void dateischreiben(const char *dateiname, int noten[],float (*f)(int[],int), int anzahl);

void dateilesen(const char dateiname);

int main(void){
    int noten[100];
    int anzahl=0;
    char bed='\0';
    char dateioperator;
    char dateieingabe[100];
    //FILE *datei=fopen("test.txt","a");

    while(bed!='q'){
        printf("Waehle:\nh for hinzufuegen\na for alle anzeigen\nd for Durchschnitt\nb for beste note\ns fuer schlechteste\nz um Datei zu schreiben oder lesen\nq zum beenden ");
        scanf(" %c", &bed);
        switch (bed){
            case 'h':
            note_hinzufuegen(noten, &anzahl);
            break;
            case 'a':
            noten_anzeigen(noten,anzahl);

            break;
            case 'd':
            printf("Der Durhschnitt betraegt %.2f\n", durchschnitt(noten,anzahl));

            break;
            case'b':
            printf("Die beste Note ist%d\n", beste_note(noten,anzahl));


            break;
            case's':
            printf("Die schlechteste Note ist%d\n", schlechteste_note(noten,anzahl));

            break;
            case 'z':
            printf("w fuer schreiben r zum lesen");
            scanf(" %c", &dateioperator);
            if(dateioperator=='w'){
                printf("Wie wollen Sie ihre Datei nennen?");
                scanf("%99s", dateieingabe);
                dateischreiben(dateieingabe,noten,durchschnitt,anzahl);
            }
            /*else if(dateioperator=='r'){
                dateilesen();
            }*/
            else{
                printf("invalid command");
            }
            break;
            case'q':
            return 0;
            default:
            printf("Invalid command");
        }
    
    }
    
    return 0;
}

void note_hinzufuegen(int noten[], int *panzahl){
    printf("Bitte Note 1-5 eingeben: ");
    scanf("%d", &noten[*panzahl]);
        
    (*panzahl) ++;

}
void noten_anzeigen(int noten[], int anzahl){
    for(int i=0; i< anzahl; i++){
        printf("%d\n", noten[i]);
    }
      
}
float durchschnitt(int noten[], int anzahl){
    float erg=0;
    if(anzahl == 0){
    return 0;}

    for(int i=0; i< anzahl; i++){
        erg+=noten[i];
    }
    
    return erg/anzahl;
}
int beste_note(int noten[], int anzahl){
    int best=noten[0];
    for(int i=0; i<anzahl; i++){
        if(noten[i]<best){
            best=noten[i];
        }
    }
    return best;
}
int schlechteste_note(int noten[], int anzahl){
    int worst=noten[0];
    for(int i=0; i<anzahl; i++){
        if(noten[i]>worst){
            worst=noten[i];
        }
    }
    return worst;

}
void dateischreiben(const char *dateiname, int noten[],float (*f)(int[],int),int anzahl){

    
    char eingabe;
    FILE *datei=fopen(dateiname,"w");
    if (datei==NULL){
        printf("Datei konnte nicht geoeffnet werden");
        return;
    }
    printf("Was wollen sie in die Datei schreiben?\na fuer alle Noten\nd fuer durchschnitt\nb fuer beides");
    scanf(" %c", &eingabe);
    switch(eingabe){
        case 'a':
        for(int i = 0; i < anzahl; i++){
            fprintf(datei, "%d\n", noten[i]);
        }
        break;
        case 'd':
        fprintf(datei,"%.2f\n",f(noten,anzahl));
        break;
       /* case 'b':
        fprintf(datei,noten,*durchschnitt);

        break;*/
    }
    fclose(datei);

}

void dateilesen(const char dateiname){

}




