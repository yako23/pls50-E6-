#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include<math.h>
#include <string.h>

char getnextcard(char *a,char *b,char *c,char *d);              //Dhlwsh function gia epomenh karta
int isSet(char *checknum,char *checkifi,char *checksxima,char *checkxroma,int *vathmoi);    //Dhlwsh function gia na elegxei an egine SET

struct paixtes                                                  //Domh dedomenwn gia tous paixtes
{
char name[17];
int score;
char id;
};

int main()                                      //Enar3h kuriws programmatos
{
char checknum[3];                                           //Dhlwsh metavlhtwn
char checkifi[3];
char checksxima[3];
char checkxroma[3];
int change;
int vathmoi=0;
int ep;                                             //Dhlwsh metrhth gia epanalhpsh
char ident;                                        //Dhlwsh gia to id tou paixth

struct paixtes x,y,z;                                //Symplhrwsh stoixeiwn paixtwn 3 paixtwn
strcpy(x.name, "Marina Andreou");
x.score = 0;
x.id = 'a';

strcpy(y.name, "Kostas Grammenos");
y.score = 0;
y.id = 'g';

strcpy(z.name, "Maria Perdika");
z.score = 0;
z.id = 'p';
int i,j,k;;                                                         //Dhlwsh metrhtwn fia epanalhpseis
srand(time(NULL));                                                  //Synarthsh gia tyxaia epilogh
char maincolour[12],mainnumber[12],mainshape[12],mainifi[12];
char colour[3],number[3],shape[3],ifi2[3];
char a,b,c,d;
for (j=0;j<12;j++)
{
    getnextcard(&a, &b, &c, &d);                                //function pou epistrefei metavlhtes
    maincolour[j]=a;                                            //oi metavlhtes autes pou pairnw mpainoun se pinakes
    mainnumber[j]=b;
    mainshape[j]=c;                               //Th 1h fora pou 8a mpei sth for 8a ektypwsei mia karta
    mainifi[j]=d;                                 //Ka8e epomenh fora 8a elegxei th karta me th 1h th 2h kok...mexri th j-1 karta

    if (j!=0)                                           //Elegxos gia na min dw8oun tyxaia idies kartes
    {
        k=1;
        while (k<=j)
        {
            change=0;
            if(maincolour[j]==maincolour[k-1]&&mainnumber[j]==mainnumber[k-1]&&mainshape[j]==mainshape[k-1]&&mainifi[j]==mainifi[k-1] )
            {
                getnextcard(&a, &b, &c, &d);
                maincolour[j]=a;
                mainnumber[j]=b;
                mainshape[j]=c;
                mainifi[j]=d;
                k=1;
                change=change+1;
            }
            if(change==0)               //An den isxuei i panw if 8a mpei se auth thn if
            {
                k=k+1;
            }
        }
    }
    if (j==4||j==8)                                     //Gia tin apeikonish se plegma an isxyei to if katevainei mia grammh
        printf("\n[%c,%c,%c,%c] ",maincolour[j],mainshape[j],mainnumber[j],mainifi[j]);
    else
        printf("[%c,%c,%c,%c] ",maincolour[j],mainshape[j],mainnumber[j],mainifi[j]);
}
printf("\n");

printf("Dwse id paixti:");                                  //Zhtaei na pai3ei paixths kai na ginei energos o sygkekrimenos
scanf("%c",&ident);

while (ident!='0'||x.score>=10||y.score>=10||z.score>=10)    //An dw8ei ident '0' h to score kapoiou paixth einai >=10 termatizei to paixnidi
{
    switch(ident)
    {
    case 'a':                                           //Periptwsh pou paizei o 'a'
    printf("Paizei i %s\n", x.name);
    int ep,k,m;
    for (ep=0; ep<3; ep++)
	{
        printf("\nParakalw dwse suntetagmenes x:");				//pairnei suntetagmenes tou x
        scanf("%d",&k);
        printf("\n");
        if (k<0||k>2)												//elegxei an einai swstes
        {
            do																//kanei epanalipsi k 3anazhtaei an den einai swstes
            {
                printf("Parakalw dwse swstes suntetagmenes x:");
                scanf("%d",&k);
            }while (k<0||k>2);
        }
        printf("x=%d\n",k);												//ektypwnei to x
        printf("Parakalw dwse suntetagmenes y:");							//pairnei suntetagmenes
        scanf("%d",&m);
        printf("\n");
        if (m<0||m>3)															//elegxei an einai swstes
        {
            do																				//kanei epanalipsi an den einai
            {
                printf("Parakalw dwse swstes suntetagmenes y:");
                scanf("%d",&m);
            }while (m<0||m>3);
        }
        printf("y=%d\n",m);															//ektypwnei to y
        if (k==0)                                                               //An vrisketai sth 1h grammh tou plegmatos
        {
            printf("[%c,%c,%c,%c] ",maincolour[m],mainshape[m],mainnumber[m],mainifi[m]);   //Ektypwnei th karta pou epele3e o paixths
            checkxroma[ep]=maincolour[m];                                           //Vazei se pinakes ta stoixeia ths kartas pou epilex8hke
            checksxima[ep]=mainshape[m];
            checknum[ep]=mainnumber[m];
            checkifi[ep]=mainifi[m];
        }
        if (k==1)                                                                //An vrisketai sth 2h grammh tou plegmatos
        {
            printf("[%c,%c,%c,%c] ",maincolour[m+4],mainshape[m+4],mainnumber[m+4],mainifi[m+4]);     //Ektypwnei th karta pou epele3e o paixths
            checkxroma[ep]=maincolour[m+4];                                       //Vazei se pinakes ta stoixeia ths kartas pou epilex8hke
            checksxima[ep]=mainshape[m+4];
            checknum[ep]=mainnumber[m+4];
            checkifi[ep]=mainifi[m+4];
        }
        if (k==2)                                                                //An vrisketai sth 3h grammh tou plegmatos
        {
            printf("[%c,%c,%c,%c] ",maincolour[m+8],mainshape[m+8],mainnumber[m+8],mainifi[m+8]);   //Ektypwnei th karta pou epele3e o paixths
            checkxroma[ep]=maincolour[m+8];                                      //Vazei se pinakes ta stoixeia ths kartas pou epilex8hke
            checksxima[ep]=mainshape[m+8];
            checknum[ep]=mainnumber[m+8];
            checkifi[ep]=mainifi[m+8];
        }
	}
	isSet(&checkxroma,&checksxima,&checkifi,&checknum,&vathmoi);            //kalei sunarthsh gia na eleg3ei an oi 3 kartes kanoun SET

    x.score= x.score+vathmoi;                                       //Pairnei tous pontous apo thn isSet k tous pros8etei sto score(apo th struct) tou sugkekrimenou paixti
    if (x.score<0)
    {                                        //Minimum va8mologia to 0
        x.score=0;
        printf("\nH va8mologia sou einai:%d\n\n",x.score);
    }
    if (vathmoi==2)                     //An egine SET diladi k epestepse 2 kerdismenous pontous dinei nea 12ada kartwn
    {
        for (j=0;j<12;j++)
        {
            getnextcard(&a, &b, &c, &d);
            maincolour[j]=a;
            mainnumber[j]=b;
            mainshape[j]=c;
            mainifi[j]=d;

            if (j!=0)
            {
                k=1;
                while (k<=j)
                {
                    change=0;
                    if(maincolour[j]==maincolour[k-1]&&mainnumber[j]==mainnumber[k-1]&&mainshape[j]==mainshape[k-1]&&mainifi[j]==mainifi[k-1] )
                    {
                        getnextcard(&a, &b, &c, &d);
                        maincolour[j]=a;
                        mainnumber[j]=b;
                        mainshape[j]=c;
                        mainifi[j]=d;
                        k=1;
                        change=change+1;
                    }
                    if(change==0)
                    {
                        k=k+1;
                    }
                }
            }
            if (j==4||j==8)
                printf("\n[%c,%c,%c,%c] ",maincolour[j],mainshape[j],mainnumber[j],mainifi[j]);
            else
                printf("[%c,%c,%c,%c] ",maincolour[j],mainshape[j],mainnumber[j],mainifi[j]);

        }
    }
    else
    {
        for (j=0;j<12;j++)                          //Emfanizei tin idia 12ada kartwn an den kanei set o paixtis pou htan energos
        {
            if (j==4||j==8)
                printf("\n[%c,%c,%c,%c] ",maincolour[j],mainshape[j],mainnumber[j],mainifi[j]);
            else
                printf("[%c,%c,%c,%c] ",maincolour[j],mainshape[j],mainnumber[j],mainifi[j]);
        }
        printf("\n");

    }
    printf("\n");
    break;
    case 'g':                                                     //Periptwsh pou paizei o 'g'
    printf("Paizei o %s\n", y.name);
    for (ep=0; ep<3; ep++)
    {
        printf("\nParakalw dwse suntetagmenes x:");
        scanf("%d",&k);                                             //pairnei suntetagmenes
        printf("\n");
        if (k<0||k>2)												//elegxei an einai swstes
        {
            do																//kanei epanalipsi an den einai
            {
                printf("Parakalw dwse swstes suntetagmenes x:");
                scanf("%d",&k);
            }while (k<0||k>2);
        }
        printf("x=%d\n",k);												//ektypwnei to x
        printf("Parakalw dwse suntetagmenes y:");							//pairnei suntetagmenes
        scanf("%d",&m);
        printf("\n");
        if (m<0||m>3)															//elegxei an einai swstes
        {
            do																				//kanei epanalipsi an den einai
            {
                printf("Parakalw dwse swstes suntetagmenes y:");
                scanf("%d",&m);
            }while (m<0||m>3);
        }
        printf("y=%d\n",m);															//ektypwnei to y
        if (k==0)
        {
            printf("[%c,%c,%c,%c] ",maincolour[m],mainshape[m],mainnumber[m],mainifi[m]);
            checkxroma[ep]=maincolour[m];
            checksxima[ep]=mainshape[m];
            checknum[ep]=mainnumber[m];
            checkifi[ep]=mainifi[m];
        }
        if (k==1)
        {
            printf("[%c,%c,%c,%c] ",maincolour[m+4],mainshape[m+4],mainnumber[m+4],mainifi[m+4]);
            checkxroma[ep]=maincolour[m+4];
            checksxima[ep]=mainshape[m+4];
            checknum[ep]=mainnumber[m+4];
            checkifi[ep]=mainifi[m+4];
        }
        if (k==2)
        {
            printf("[%c,%c,%c,%c] ",maincolour[m+8],mainshape[m+8],mainnumber[m+8],mainifi[m+8]);
            checkxroma[ep]=maincolour[m+8];
            checksxima[ep]=mainshape[m+8];
            checknum[ep]=mainnumber[m+8];
            checkifi[ep]=mainifi[m+8];
        }
    }

    isSet(&checkxroma,&checksxima,&checkifi,&checknum,&vathmoi);

    y.score= y.score+vathmoi;
    if (y.score<0)
    {
        y.score=0;
        printf("\nH va8mologia sou einai:%d\n\n",y.score);
    }

    if (vathmoi==2)
    {
        for (j=0;j<12;j++)
        {
            getnextcard(&a, &b, &c, &d);
            maincolour[j]=a;
            mainnumber[j]=b;
            mainshape[j]=c;
            mainifi[j]=d;

            if (j!=0)
            {
                k=1;
                while (k<=j)
                {
                    change=0;
                    if(maincolour[j]==maincolour[k-1]&&mainnumber[j]==mainnumber[k-1]&&mainshape[j]==mainshape[k-1]&&mainifi[j]==mainifi[k-1] )
                    {
                        getnextcard(&a, &b, &c, &d);
                        maincolour[j]=a;
                        mainnumber[j]=b;
                        mainshape[j]=c;
                        mainifi[j]=d;
                        k=1;
                        change=change+1;
                    }
                    if(change==0)
                    {
                        k=k+1;
                    }
                }
            }
            if (j==4||j==8)
                printf("\n[%c,%c,%c,%c] ",maincolour[j],mainshape[j],mainnumber[j],mainifi[j]);
            else
                printf("[%c,%c,%c,%c] ",maincolour[j],mainshape[j],mainnumber[j],mainifi[j]);

        }
    }
    else
    {
        for (j=0;j<12;j++)                          //Emfanizei tin idia 12ada kartwn an den kanei set o paixtis pou htan energos
        {
            if (j==4||j==8)
                printf("\n[%c,%c,%c,%c] ",maincolour[j],mainshape[j],mainnumber[j],mainifi[j]);
            else
                printf("[%c,%c,%c,%c] ",maincolour[j],mainshape[j],mainnumber[j],mainifi[j]);
        }
        printf("\n");
    }
    printf("\n");
    break;
    case 'p':                                   //Periptwsh pou paizei o 'p'
    printf("Paizei i %s\n", z.name);
    for (ep=0; ep<3; ep++)
	{
        printf("\nParakalw dwse suntetagmenes x:");				//pairnei suntetagmenes
        scanf("%d",&k);
        printf("\n");
        if (k<0||k>2)												//elegxei an einai swstes
        {
            do																//kanei epanalipsi an den einai
            {
                printf("Parakalw dwse swstes suntetagmenes x:");
                scanf("%d",&k);
            }while (k<0||k>2);
        }
        printf("x=%d\n",k);												//ektypwnei to x
        printf("Parakalw dwse suntetagmenes y:");							//pairnei suntetagmenes
        scanf("%d",&m);
        printf("\n");
        if (m<0||m>3)															//elegxei an einai swstes
        {
            do																				//kanei epanalipsi an den einai
            {
                printf("Parakalw dwse swstes suntetagmenes y:");
                scanf("%d",&m);
            }while (m<0||m>3);
        }
        printf("y=%d\n",m);															//ektypwnei to y
        if (k==0)
        {
            printf("[%c,%c,%c,%c] ",maincolour[m],mainshape[m],mainnumber[m],mainifi[m]);
            checkxroma[ep]=maincolour[m];
            checksxima[ep]=mainshape[m];
            checknum[ep]=mainnumber[m];
            checkifi[ep]=mainifi[m];
        }
        if (k==1)
        {
            printf("[%c,%c,%c,%c] ",maincolour[m+4],mainshape[m+4],mainnumber[m+4],mainifi[m+4]);
            checkxroma[ep]=maincolour[m+4];
            checksxima[ep]=mainshape[m+4];
            checknum[ep]=mainnumber[m+4];
            checkifi[ep]=mainifi[m+4];
        }
        if (k==2)
        {
            printf("[%c,%c,%c,%c] ",maincolour[m+8],mainshape[m+8],mainnumber[m+8],mainifi[m+8]);
            checkxroma[ep]=maincolour[m+8];
            checksxima[ep]=mainshape[m+8];
            checknum[ep]=mainnumber[m+8];
            checkifi[ep]=mainifi[m+8];
        }
	}
    isSet(&checkxroma,&checksxima,&checkifi,&checknum,&vathmoi);

    z.score=z.score+vathmoi;
    if (z.score<0)
    {
        z.score=0;
        printf("\nH va8mologia sou einai:%d\n\n",z.score);
    }

    if (vathmoi==2)                                             //Emfanish neas 12adas kartwn
    {
        for (j=0;j<12;j++)
        {
            getnextcard(&a, &b, &c, &d);
            maincolour[j]=a;
            mainnumber[j]=b;
            mainshape[j]=c;
            mainifi[j]=d;

            if (j!=0)
            {
                k=1;
                while (k<=j)
                {
                    change=0;
                    if(maincolour[j]==maincolour[k-1]&&mainnumber[j]==mainnumber[k-1]&&mainshape[j]==mainshape[k-1]&&mainifi[j]==mainifi[k-1] )
                    {
                        getnextcard(&a, &b, &c, &d);
                        maincolour[j]=a;
                        mainnumber[j]=b;
                        mainshape[j]=c;
                        mainifi[j]=d;
                        k=1;
                        change=change+1;
                    }
                    if(change==0)
                    {
                        k=k+1;
                    }
                }
            }
            if (j==4||j==8)
                printf("\n[%c,%c,%c,%c] ",maincolour[j],mainshape[j],mainnumber[j],mainifi[j]);
            else
                printf("[%c,%c,%c,%c] ",maincolour[j],mainshape[j],mainnumber[j],mainifi[j]);

        }
    }
    else
    {
        for (j=0;j<12;j++)                          //Emfanizei tin idia 12ada kartwn an den kanei set o paixtis pou htan energos
        {
            if (j==4||j==8)
                printf("\n[%c,%c,%c,%c] ",maincolour[j],mainshape[j],mainnumber[j],mainifi[j]);
            else
                printf("[%c,%c,%c,%c] ",maincolour[j],mainshape[j],mainnumber[j],mainifi[j]);
        }
        printf("\n");
    }
    printf("\n");
    break;
    case '0':                                   //Periptwsi 0 termatizei to paixnidi k emfanizei ti va8mologia twn paixtwn
    printf("\n\nTelos paixnidiou\n");
    printf("%s vathmologia = %d\n%s vathmologia = %d\n%s vathmologia = %d\n",x.name,x.score,y.name,y.score,z.name,z.score);
    if (x.score>=10)                            //An kapoios paixths sygkentrwse panw apo 10 pontous ektypwnei to onoma tou
    printf("O nikhths einai h %s",x.name);
    else if (y.score>=10)
    printf("O nikhths einai o %s",y.name);
    else if (z.score>=10)
    printf("O nikhths einai h %s",z.name);
    exit(1);
    default:                            //An o xrhsths plhktrologhsei otidhpote allo plhn twn id twn paixtwn emfanizei nea 12ada kartwn
    for (j=0;j<12;j++)
    {
        getnextcard(&a, &b, &c, &d);
        maincolour[j]=a;
        mainnumber[j]=b;
        mainshape[j]=c;
        mainifi[j]=d;

        if (j!=0)
        {
            k=1;
        while (k<=j)
        {
            change=0;
            if(maincolour[j]==maincolour[k-1]&&mainnumber[j]==mainnumber[k-1]&&mainshape[j]==mainshape[k-1]&&mainifi[j]==mainifi[k-1] )
            {
                getnextcard(&a, &b, &c, &d);
                maincolour[j]=a;
                mainnumber[j]=b;
                mainshape[j]=c;
                mainifi[j]=d;
                k=1;
                change=change+1;
            }
            if(change==0)
            {
                k=k+1;
            }
        }
    }
    if (j==4||j==8)
        printf("\n[%c,%c,%c,%c] ",maincolour[j],mainshape[j],mainnumber[j],mainifi[j]);
    else
        printf("[%c,%c,%c,%c] ",maincolour[j],mainshape[j],mainnumber[j],mainifi[j]);
    }
    }
    printf("\n");
    printf("\nDwse id paixti:\n");
    getchar();
    ident=getchar();
}
printf("\n\nTelos paixnidiou\n");
printf("%s vathmologia = %d\n%s vathmologia = %d\n%s vathmologia = %d\n",x.name,x.score,y.name,y.score,z.name,z.score);
if (x.score>=10)
    printf("O nikhths einai h %s",x.name);
else if (y.score>=10)
    printf("O nikhths einai o %s",y.name);
else if (z.score>=10)
    printf("O nikhths einai h %s",z.name);
return 0;
}


int isSet(char *checknum,char *checkifi,char *checksxima,char *checkxroma,int *vathmoi)     //Synarthsh pou elegxei an exei ginei SET
{
   printf("funct vathmoi = %d",*vathmoi);
    //Elegxoi an h epilogh tou xrhsth apotelei SET
    if (checkxroma[0]==checkxroma[1]&&checkxroma[1]==checkxroma[2]&&checksxima[0]==checksxima[1]&&checksxima[1]==checksxima[2]&&checkifi[0]==checkifi[1]&&checkifi[1]==checkifi[2]&&checknum[0]!=checknum[1]&&checknum[1]!=checknum[2])
    {
        printf("Egine set\n");
        *vathmoi=2;                                      //Au3hsh ths va8mologias an ekane SET
        printf("\nKerdises %d vathmous\n",*vathmoi);
    }
    else if(checkxroma[0]!=checkxroma[1]&&checkxroma[1]!=checkxroma[2]&&checksxima[0]==checksxima[1]&&checksxima[1]==checksxima[2]&&checkifi[0]==checkifi[1]&&checkifi[1]==checkifi[2]&&checknum[0]==checknum[1]&&checknum[1]==checknum[2])
    {
        printf("Egine set");
        *vathmoi=2;
        printf("\nKerdises %d vathmous\n",*vathmoi);
    }
    else if(checkxroma[0]!=checkxroma[1]&&checkxroma[1]!=checkxroma[2]&&checksxima[0]!=checksxima[1]&&checksxima[1]!=checksxima[2]&&checkifi[0]!=checkifi[1]&&checkifi[1]!=checkifi[2]&&checknum[0]==checknum[1]&&checknum[1]==checknum[2])
    {
        printf("Egine set");
        *vathmoi=2;
        printf("\nKerdises %d vathmous\n",*vathmoi);
    }
    else if(checkxroma[0]==checkxroma[1]&&checkxroma[1]==checkxroma[2]&&checksxima[0]!=checksxima[1]&&checksxima[1]!=checksxima[2]&&checkifi[0]==checkifi[1]&&checkifi[1]==checkifi[2]&&checknum[0]==checknum[1]&&checknum[1]==checknum[2])
    {
        printf("Egine set");
        *vathmoi=2;
        printf("\nKerdises %d vathmous\n",*vathmoi);
    }
    else if(checkxroma[0]==checkxroma[1]&&checkxroma[1]==checkxroma[2]&&checksxima[0]==checksxima[1]&&checksxima[1]==checksxima[2]&&checkifi[0]!=checkifi[1]&&checkifi[1]!=checkifi[2]&&checknum[0]==checknum[1]&&checknum[1]==checknum[2])
    {
        printf("Egine set");
        *vathmoi=2;
        printf("\nKerdises %d vathmous\n",*vathmoi);
    }
    else                                        //Periptwsh pou den exei ginei SET
    {
        printf("\nSorry alla den egine set\n");
        *vathmoi=-1;                          //Meiwsh va8mologias xrhsth
        printf("\n Sou afairethikan %d vathmoi\n",*vathmoi);
    }
    return *vathmoi;
};


char getnextcard(char *a,char *b,char *c,char *d)           //Synarthsh gia emfanish diaforetikhs kartas
{
        int i,xroma,sxima,ifi,arithmo;
        char colour[3]={'r','g','b'};
        char shape[3]={'c','t','r'};
        char ifi2[3]={'b','h','e'};
        char number[3]={'1','2','3'};
        xroma = rand()%3;
        sxima = rand()%3;
        ifi = rand()%3;
        arithmo = rand()%3;
        *a=colour[xroma];
        *b=number[arithmo];
        *c=shape[sxima];
        *d=ifi2[ifi];
        return a,b,c,d;
}



