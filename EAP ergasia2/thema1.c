#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct stoixeia
{
    char onomaepwnumo[40];
    unsigned int ar_thes;
    unsigned short int ar_til[10];
};

void epilogi1(struct stoixeia passenger[],int seats);
void epilogi2(struct stoixeia passenger[],int seats,int kratisi);
void epilogi3(struct stoixeia passenger[],int seats);
void epilogi4(struct stoixeia passenger[],int seats,int akirwsh);
void epilogi5(struct stoixeia passenger[],int seats);

int main(void)
{

	int i;
	int found,found2,choice,kenes=0;

	FILE *f_in,*f_out;
	f_in = fopen("bus.txt", "r");
	if ( f_in != NULL )
	{

		char name[40], name2[40];
    	char surname[40], surname2[40];
    	char bus_plate[10];
    	int anazitisi;
    	char anazitname[40];
    	int seat_number,seats,kratisi,anazitisitilefwno,akirwsh;
    	int anatilefwno[10];
    	int i,j,k;

    	struct stoixeia passenger[53];

        fscanf(f_in, "%s %d\n", &bus_plate, &seats);            //Diavasma apo arxeio bus.txt tis pinakidas k tou pli8ous 8esewn
        printf("%s %d\n",bus_plate,seats);                      //Ektypwsh tous

        //Arxikopoihsh pinaka thesewn wste na einai kenes kata thn enar3h tou programmatos
    	for (i=0; i<seats; i++)
    	{
        	for (j=0;j<40;j++)
        	{
            	passenger[i].onomaepwnumo[j]='\0';
        	}
        	passenger[i].ar_thes=i+1;
        	for (k=0;k<10;k++)
        	{
            	passenger[i].ar_til[k]=0;
        	}
        }
    //Diavasma upoloipou arxeiou k apo8ikeush twn stoixeiwn tou
        while( !feof(f_in) )
        {

        fscanf(f_in, "%s %s %d",&surname, &name, &seat_number);

        for(i=0; i<10; i++)
        {
            fscanf(f_in, "%1hu", &passenger[seat_number-1].ar_til[i]);
        }
        strcpy(passenger[seat_number - 1].onomaepwnumo, surname);
        strcat(passenger[seat_number - 1].onomaepwnumo, " ");
        strcat(passenger[seat_number - 1].onomaepwnumo, name);
        //Store the passenger's seat nuamber
        passenger[seat_number - 1].ar_thes = seat_number;
        }
        //Tha mporousame na ektypwsoume mia lista me tis krathmenes theseis k me ta stoixeia twn epivatwn k ta upoloipa 8a grafoun KENO
    	for (i=0;i<seats;i++)
    	{
        //	printf("\n%s\t",passenger[i].onomaepwnumo);
        //	printf("%u\t",passenger[i].ar_thes);
        	for(k=0; k<10; k++)
        	{
            //	printf("%1hu",passenger[i].ar_til[k]);
            }
        	//printf("\n");
    	}
        //printf("\n\n");
        for (i=0;i<seats;i++)
        {
            j=0;
            while(j<=40)
            {
                if(passenger[i].onomaepwnumo[j]=='\0'&&j==0)
                {
                    //printf("KENO \t %d \t KENO\n",i+1);
                    j=41;
                }
                j=j+1;
            }
			if(passenger[i].onomaepwnumo[0]!='\0')
            {
               // printf("%s\t",passenger[i].onomaepwnumo);
                //printf("%u\t",passenger[i].ar_thes);
                for(k=0; k<10; k++)
                {
                    //printf("%1hu",passenger[i].ar_til[k]);
                }
                //printf("\n");
            }
        }

        choice = 1;                 //arxikopoihsh ths epiloghs
        while(choice!=0)            //Emfanish menu epilogwn
        {
            printf("\n\n1. emfanish synolikoy plhthous kenwn thesewn kai twn arithmwn  tous\n");
            printf("2. krathsh theshs me sygkekrimeno arithmo\n");
            printf("3. anazhthsh gia to an einai krathmenh thesh me sygkekrimeno arithmo\n");
            printf("4. akyrwsh krathshs theshs me sygkekrimeno arithmo\n");
            printf("5. emfanish listas krathmenwn thesewn taksinomhmenhs kata arithmo theshs\n");
            printf("0. termatismos\n");
            printf("Parakalw kante mia epilogi apo to menu: ");
            scanf("%d",&choice);

            switch(choice)
            {
				case 1:
				epilogi1(passenger,seats);          //kalesma synarthshs gia epilogh 1
            	break;
            	case 2:
	            printf("\nDwse arithmo theshs:");
             	scanf("%d",&kratisi);                       //Zitame ari8mo tis theshs pou 8eloume na kanoume krathsh
             	epilogi2(passenger,seats,kratisi);          //kalesma synarthshs gia epilogh 2
                break;
                case 3:
            	epilogi3(passenger,seats);                  //kalesma synarthshs gia epilogh 3
				break;
                case 4:
		            printf("\nDwse arithmo theshs pros akirwsh:");
            		scanf("%d",&akirwsh);                       //Zitame ari8mo tis theshs pou 8eloume na kanoume akyrwsh
            		epilogi4(passenger,seats,akirwsh);          //kalesma synarthshs gia epilogh 4
            		break;
                case 5:
            	printf("\n");
            	epilogi5(passenger,seats);                      //kalesma synarthshs gia epilogh 5
            	break;
				case 0:                                         //Periptwsh 0 telos programmatos
				break;
                default:                                        //Periptwsh pou plhktrologh8ei allh apo tis 6 epiloges
            	printf("akatallili epilogi\n");
         	}
        }

        f_out = fopen("bus.txt", "w");                      // Anoigei to arxeio e3odou
        if(f_out == NULL)                           // se periptwsi problimatos kata to anoigma
        {
            printf("To arxeio bus.txt den mporese na anoixtei\n");
            exit(1);
        }
        fprintf(f_out,"%s %d\n",bus_plate,seats);           //Ektypwnei 3ana pinakida k 8eseis
        for (i=0;i<seats;i++)                               //Ektypwsh twn stoixeiwn twn epivatwn pou exoun kanei krathsh
        {
            if(passenger[i].onomaepwnumo[0]!='\0')
            {
                fprintf(f_out,"%s\t",passenger[i].onomaepwnumo);
                fprintf(f_out,"%u\t",passenger[i].ar_thes);
                for(k=0; k<10; k++)
                {
                    fprintf(f_out,"%1hu",passenger[i].ar_til[k]);
                }
                fprintf(f_out,"\n");
            }
        }
        fprintf(f_out,"\n");
        fclose(f_out);                      // kleise to arxeio e3odou
    }
	else
	{
		printf("To arxeio bus.txt de mporese na anagnwstei\n");     // se periptwsi problimatos kata to anoigma
    	exit(1);      // e3odos apo to programma
	}
	fclose(f_in);    // kleisimo arxeiou eisodou
}



void epilogi1(struct stoixeia passenger[],int seats)        //Synarthsh gia ektelesh epiloghs 1
{
    int i,kenes=0;
    printf("\n[");
    for (i=0;i<seats;i++)
    {
        if (passenger[i].onomaepwnumo[0]=='\0')         //An to 1o stoixeio tou pinaka onomaepwnumo=\0 shmainei pws den yparxei
        {                                               //krathsh se ayth th 8esh
            kenes=kenes+1;
            printf("%d,",i+1);
        }
    }
    printf("]\n\n");
    printf("Sunolo thesewn: %d \nPlithos kenwn thesewn:%d\n",seats,kenes);
}


void epilogi2(struct stoixeia passenger[],int seats,int kratisi)        //Synarthsh gia ektelesh epiloghs 2
{
    char surname[40],name[40];
    int i,k;
    if (kratisi<1 || kratisi>seats) // elegxos oti arithmos thesis entos oriwn
    {
        printf("\narithmos thesis ektos oriwn\n");
    }
    else
    {
        if (passenger[kratisi-1].onomaepwnumo[0] =='\0') // an einai eleutheri
        {
            printf("\nDwse epitheto kai onoma:");
            scanf("%s %s",&surname, &name);
            strcpy(passenger[kratisi - 1].onomaepwnumo, surname);       //Vazoume to onoma k to epi8eto se ena pinaka
            strcat(passenger[kratisi - 1].onomaepwnumo, " ");
            strcat(passenger[kratisi - 1].onomaepwnumo, name);
            printf("\nDwse arithmo tilefwnou(Parakalw PSIFIO - PSIFIO):");
            for (i=0;i<10;i++)
            {
                scanf("%d",&passenger[kratisi-1].ar_til[i]);        //zitame apo to xrhsth na dwsei to thlefwno psifio psifio
            }
            // kratise tin
            passenger[kratisi-1].ar_thes=kratisi;
            printf("\nThesi kratithike\n");
        }
        else
        printf("Thesi idi kateilhmmeni\n");
    }
}

void epilogi3(struct stoixeia passenger[],int seats)            //Synarthsh gia ektelesh epiloghs 3
{
    int anazitisi,i,j,anatilefwno[10],found2;
    char surname2,name2,anazitname;
    printf("\nThelete anazitisi me onoma(1) h tilefwno(2):");
    scanf("%d",&anazitisi);                 //O xrhsths epilegei 1 h 2 analoga me to tropo anazhthshs pou 8elei
    if (anazitisi==1)                       //Anazhthsh me vash onomate/nymo
    {
        printf("\nDwse epitheto:");
        scanf("%s",&surname2);
        printf("\nDwse onoma:");
        scanf("%s",&name2);
        strcpy(anazitname, surname2);       //Enwnoume to onoma me to epi8eto
        strcat(anazitname, " ");
        strcat(anazitname, name2);
        printf("%s", anazitname);
        int i=0;
        int flag = 0;                           //Deikths pou an ginei 1 to vrhke
        while (flag==0 && i<seats)
        {
            if (strcmp(passenger[i].onomaepwnumo, anazitname) == 0) //Sugkrisi onomatos ka8e epivath me auto pou dw8hke
                flag = 1;                   //vre8hke
            else
                i = i+1;                    //an de vre8hke au3hse kata 1 ton metrhth
        }
        if (flag == 0)                  //An oloklhrw8ei h epanalhpsh gia oles tis 8eseis tou lewforeiou k flag=0
            printf("\nDen yparxei krathmenh thesh se auto to onoma");
        else
            printf("\nYparxei krathsh sauto to onoma sth thesh %d",i+1);
    }
    else if(anazitisi==2)               //Anazhthsh me vash to tilefwno
    {
        printf("Dwse arithmo tilefwnou(Parakalw PSIFIO - PSIFIO):");
        for (i=0;i<10;i++)
        {
            scanf("%d",&anatilefwno[i]);
        }
        for (i=0;i<seats;i++)           //Gia oles tis 8eseis tou lewforeiou
        {
            found2=0;
            for (j=0;j<10;j++)
            {
                if(passenger[i].ar_til[j]==anatilefwno[j])      //An to ka8e psifio pou dwsame einai idio me to ka8e psifio tou tilefwnou pou yparxei
                {
                    found2=found2+1;
                }
            }
            if (found2==10)         //An ola ta psifia einai idia vre8hke h 8esh
            {
                printf("thesh kratimenh sto onoma %s ",passenger[i].onomaepwnumo);
            }
            if (i==seats-1&&found2!=10)
                printf("\nDe vrethike o arithmos autos");
        }
    }
}

void epilogi4(struct stoixeia passenger[],int seats,int akirwsh)        //Synarthsh gia ektelesh epiloghs 4
{
    int i,j;
    while (akirwsh<1 || akirwsh>seats) // elegxos oti arithmos thesis entos oriwn
    {
        printf("\narithmos thesis ektos oriwn\n");
        printf("Dwse 3ana swsto arithmo theshs pros akirwsh:");
        scanf("%d",&akirwsh);           //Zhtaei ari8mo 8eshs gia akyrwsh
    }
    j=0;
    if (passenger[akirwsh-1].onomaepwnumo[j]=='\0')     //An to 10 stoixeio tou onomatos einai to \0 h 8esh einai kenh
    {
        printf("\nH thesh auth einai idi kenh\n");
    }
    else
    {
        for (j=0;j<seats;j++)
        {
            passenger[akirwsh-1].onomaepwnumo[j]='\0';      //Alliws kanei \0 th 8esh pou 8eloume
        }
        for(i=0; i<10; i++)
        {
            passenger[akirwsh-1].ar_til[i]=0;       //Mhdenizei k to tilefwno
        }
        printf("thesi apodesmeutike\n");
    }
}

void epilogi5(struct stoixeia passenger[],int seats)            //Synarthsh gia ektelesh epiloghs 5
{
    int i,k;
    for (i=0;i<seats;i++)
    {
        if(passenger[i].onomaepwnumo[0]!='\0')      //An to onom/nymo den einai \0
        {
            printf("%s\t\t",passenger[i].onomaepwnumo); //Ektypwse ta stoixeia
            for(k=0; k<10; k++)
            {
                printf("%1hu",passenger[i].ar_til[k]);
            }
            printf("\t\t%u\t",passenger[i].ar_thes);
            printf("\n");
        }
    }
}
