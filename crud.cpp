#include <iostream>

using namespace std;

void search(int v[],int &d)
{
    int val;
    cout<<"\nQuale valore vuoi cercare?";
    cin>>val;


    int pos=0;
    for(int i=0; i<d; i++)
    {
        if(v[i]==val)
        {
            pos=i+1;
        }
    }
    if(pos==0)
    {
     cout<<"Valore non trovato. -1";
    }else
    {
        cout<<"Valore si trova in posizione: "<<pos;
    }
}
void view(int v[],int &d)
{
    for(int i=0;i<d;i++)
    {
        cout<<"\nQuesto è il "<<i+1<<"° elemento dell'array:"<<v[i]<<endl;
    }
}

void add(int v[],int &d)
{
    int x;
    cout<<"\n\nInserire il valore: ";
    cin>>x;
    v[d]=x;
    d++;
}

void edit(int v[],int &d)
{
    int pos;
    int edit;

    cout<<"\n\nQuale posizione dell'array vorresti modificare? ";
    cin>>pos;
    while(pos>=d) //se la posizione dell'elemento inserito non esiste, si rimane nel ciclo
    {
        cout<<"\nNessun numero in posizione "<<pos<<". Riprovare: ";
        cin>>pos;
    }
    cout<<"\nInserire il numero modificato:";
    cin>>edit;
    v[pos-1]=edit;

    cout<<"\nModificato con sucesso!";



}


void erase(int v[],int &d)
{
    int pos;
    cout<<"\n\nQuale elemento dell'array vorresti eliminare?";
    cin>>pos;
    while(pos>=d) //se la posizione dell'elemento inserito non esiste, si rimane nel ciclo
    {
        cout<<"\nNessun numero in posizione "<<pos<<". Riprovare: ";
        cin>>pos;
    }

    while(pos<d)
    {
        v[pos-1]=v[pos];
        pos++;
    }
    cout<<"\nCancellato con sucesso!";
    d--;
}


int main()
{
    int opzione;
    int a[100];
    int dim=0;

    do
    {
        cout<<"0 - Ferma programma\n";
        cout<<"1 - Inserimento\n";
        cout<<"2 - Cancellazione\n";
        cout<<"3 - Modifica\n";
        cout<<"4 - Visualizzazione\n";
        cout<<"5 - Ricerca\n";
        cout<<"Scegli opzione: ";

        cin>>opzione;

        switch(opzione)
        {
            case 0: break;
            case 1: //Inserimento
                add(a,dim);
                break;
            case 2://Cancellazione
                erase(a,dim);
                break;
            case 3://Modifica
                edit(a,dim);
                break;
            case 4://Visualizzazione
                view(a,dim);
                break;
            case 5://Ricerca
                search(a,dim);
                break;

            default: //Nel caso in cui l'utente sceglie un numero diverso
            cout<<"\nOpzione non valida.\n\n";
        }

        cout<<endl<<endl<<endl<<"-----------------------------\n\n\n";

    }while(opzione!=0);


}
