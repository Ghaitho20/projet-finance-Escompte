#include<stdio.h>
#include <stdlib.h>
typedef struct{
    int jj;
    int mm;
    int a;
}date;

typedef struct{
    float taux_escompte;
    float val_nominale;
    date  date_echea;
    int njE;
    int dom;
    int plac;
    float AgjE;
    int njB;
    float AgjB;
    float AgE1;//somme
    int njCE;//npmbre de jours globale
    float AgCe;//endossement
    float AgE2;
    float agcd;//place domicilie ou nn
    float totAGht;
    float tva;
    float totagttc;
    float net_escompte;
}effet;
effet tabeffet[100];





date ecriredate(){
   int j,m,a;
   date dd;
   printf("pour construire la date sous la forme jj/mm/aa,taper le nombre de jours jj\n");
   scanf("%d",&j);
   printf("pour construire la date sous la forme jj/mm/aa,taper le nombre de mois mm\n");
   scanf("%d",&m);
   printf("pour construire la date sous la forme jj/mm/aa,taper le nombre d annee aa\n");
   scanf("%d",&a);
   dd.jj=j;
   dd.mm=m;
   dd.a=a;
   return dd;

}

int main(){
    int tab_mois[12];
    tab_mois[0]=31;tab_mois[3]=30;tab_mois[6]=31;tab_mois[9]=31;
    tab_mois[1]=28;tab_mois[4]=31;tab_mois[7]=31;tab_mois[10]=30;
    tab_mois[2]=31;tab_mois[5]=30;tab_mois[8]=30;tab_mois[11]=31;
    date date_esc;
    printf("tapez la date de l escompte auquelle les effets seront remis\n");
    date_esc= ecriredate();
    int rep=1;
    int i=0;
    float taux_endoss;
    while (rep==1){

            effet eff;
            printf("taper la valeur nominale d l escompte\n");
            scanf("%f",&eff.val_nominale);
            printf("taper le taux d escompte negocie avec la banque\n");
            scanf("%f",&eff.taux_escompte);
            printf("mainetenant nou passons a taper la date d echeance de cette effet\n");
            eff.date_echea=ecriredate();
            int s1=0;
            int s2=0;
            for (int i=0;i<date_esc.mm-1;i++){
                s1+=tab_mois[i];
            }
             for (int i=0;i<eff.date_echea.mm-1;i++){
                s2+=tab_mois[i];
            }
            int  jours1 = date_esc.jj + s1  + date_esc.a * 365;
            int jours2 = eff.date_echea.jj + s2 + eff.date_echea.a * 365;
            eff.njE=jours2 - jours1;

            eff.AgjE=(eff.val_nominale*eff.taux_escompte*eff.njE)/36000;

            printf("donner le nombre de jours de banque\n");
            scanf("%d",&eff.njB);
            eff.AgjB=(eff.val_nominale*eff.taux_escompte*eff.njB)/36000;
            eff.AgE1=eff.AgjB+ eff.AgjE;
            eff.njCE=eff.njE+eff.njB;
            printf("taper le taux d endossement s il est nulle tapez 0\n");
            scanf("%f",&taux_endoss);

            eff.AgCe=(eff.val_nominale*taux_endoss*eff.njCE)/36000;
            eff.AgE2=eff.AgCe+eff.AgE1;






            float com_plac;
            float com_dom;
            printf("taper 1 si l operation est placee 0 sinon svp\n");
            do {

                  scanf("%d",&eff.plac);
            }while(eff.plac!=0 && eff.plac!=1);
            if (eff.plac==0){
                printf("tapez les commissions de service pour les effets non placés\n");
                scanf("%f",&com_plac);

            }
            else if (eff.plac==1){
                    printf("tapez les commissions de service pour les effets placés\n");
                    scanf("%f",&com_plac);

            }
            printf("taper 1 si l operation est domiciliée 0 sinon svp\n");


            do {
                  scanf("%d",&eff.dom);
            }while(eff.dom!=0 && eff.dom!=1);
            if (eff.dom==0){
                printf("tapez les commissions de service pour les effets non domiciliés\n");
                scanf("%f",&com_dom);

            }
            else if (eff.dom==1){
                    printf("tapez les commissions de service pour les effets domiciliés\n");
                    scanf("%f",&com_dom);

            }
            eff.agcd=com_plac+com_dom;
            eff.totAGht=eff.agcd+eff.AgE2;

            float x;
            printf("tapez le taux de tva en %\n");
            scanf("%f",&x);
            eff.tva=eff.agcd*x/100;

            eff.totagttc=eff.totAGht+ eff.tva;

            eff.net_escompte=eff.val_nominale-eff.totagttc;

            tabeffet[i]=eff;
            i++;

            printf("\nsi vous avez ecrits tous les effets alors taper 0 sinon tapez 1\n");
            do {
                scanf("%d",&rep);
            }while(rep!=0 && rep!=1);
    }

    /////affichage de tableau finale
    printf("                                   bordereau\n");
    printf("                            effet(s) remis a l escompte\n");
    printf("                                    le %d/%d/%d\n",date_esc.jj,date_esc.mm,date_esc.a);
        printf("val_nominale  date_echea  njE       AgjE        njb        AgjB        AgE1       njcE        AGcE       AgE2       Agcd       totAGht       tva      totagttc    net_escompte \n");
    printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    for (int j=0;j<i;j++){
        printf("%f       %d/%d/%d     %d  %f    %d    %f   %f        %d       %f     %f      %f      %f       %f        %f        %f         \n",tabeffet[j].val_nominale,tabeffet[j].date_echea.jj,tabeffet[j].date_echea.mm,tabeffet[j].date_echea.a,tabeffet[j].njE,tabeffet[j].AgjE,tabeffet[j].njB,tabeffet[j].AgjB,tabeffet[j].AgE1,tabeffet[j].njCE,tabeffet[j].AgCe,tabeffet[j].AgE2,tabeffet[j].agcd,tabeffet[j].totAGht,tabeffet[j].tva,tabeffet[j].totagttc,tabeffet[j].net_escompte);

    }

    float effet_0=0,effet_5=0,effet_7=0,effet_8=0,effet_10=0,effet_11=0,effet_12=0,effet_13=0,effet_14=0,effet_15=0,effet_16=0;
    int effet_4=0,effet_6=0,effet_9=0;
    for (int j=0;j<i;j++){
        effet_0=effet_0+tabeffet[j].val_nominale;
        effet_4=effet_4+tabeffet[j].njE;
        effet_5=effet_5+tabeffet[j].AgjE;
        effet_6=effet_6+tabeffet[j].njB;
        effet_7=effet_7+tabeffet[j].AgjB;
        effet_8=effet_8+tabeffet[j].AgE1;
        effet_9=effet_9+tabeffet[j].njCE;
        effet_10=effet_10+tabeffet[j].AgCe;
        effet_11=effet_11+tabeffet[j].AgE2;
        effet_12=effet_12+tabeffet[j].agcd;
        effet_13=effet_13+tabeffet[j].totAGht;
        effet_14=effet_14+tabeffet[j].tva;
        effet_15=effet_15+tabeffet[j].totagttc;
        effet_16=effet_16+tabeffet[j].net_escompte;

    }
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    printf("%f          ***          %d   %f    %d     %f  %f        %d       %f    %f      %f      %f      %f        %f         %f                \n",effet_0,effet_4,effet_5,effet_6,effet_7,effet_8,effet_9,effet_10,effet_11,effet_12,effet_13,effet_14,effet_15,effet_16);




}

