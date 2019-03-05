#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

class regn
{
protected:
    string nume;
    string den_st;
    string specie;
    string med_viata;
public:
    regn(){nume="\0";};
    void set_regn(string a,string b,string c,string d){nume=a; den_st=b; specie=c; med_viata=d;};
    regn(string a,string b,string c,string d){nume=a; den_st=a; specie=c; med_viata=d;};
    ~regn(){};
    virtual void afisare();
    friend istream& operator>>(istream&,regn&);
    friend ostream& operator<<(ostream&,regn&);
    regn& operator=(const regn&);
    regn(const regn&);
};

regn::regn(const regn &a)
{
    nume=a.nume;
    den_st=a.den_st;
    specie=a.specie;
    med_viata=a.med_viata;
}

regn& regn::operator=(const regn &a)
{
    nume=a.nume;
    den_st=a.den_st;
    specie=a.specie;
    med_viata=a.med_viata;
    return *this;
}

istream& operator>>(istream &fct,regn &ob)
{  string a,b,c,d;
    cout<<"Nume: ";
    fct>>a;
    cout<<"Denumire stiintifica: ";
    fct>>b;
    cout<<"Specie: ";
    fct>>c;
    cout<<"Mediu viata(Acvatic/Terestru/Aerian): ";
    fct>>d;
    ob.set_regn(a,b,c,d);
        return fct;
}

ostream& operator<<(ostream &fct,regn &ob)
{
    ob.afisare();
    return fct;
}

void regn::afisare()
{
    cout<<"Nume:"; cout<<nume<<endl;
    cout<<"Denumire stiintifica: "; cout<<den_st<<endl;
    cout<<"Specie:"; cout<<specie<<endl;
    cout<<"Mediu viata(Acvactic/Aerian/Terestru): "; cout<<med_viata<<endl;
}

class nevertebrata:public regn
{
    double lungime;
    double greutate;
    int durata_viata;
public:
    nevertebrata(){};
    nevertebrata(string a,string b,string c,string f,double d,double e,int h):regn(a,b,c,f){lungime=d; greutate=e; med_viata=f; durata_viata=h;};
    ~nevertebrata(){cout<<"dist nevert";};
    nevertebrata(const nevertebrata&);

    friend istream& operator>>(istream &,nevertebrata &);
    friend ostream& operator<<(ostream &,nevertebrata &);
    nevertebrata& operator=(const nevertebrata&);

    void set_nev(double a,double b,int d){lungime=a; greutate=b; durata_viata=d;};
    void afisare();



};

istream& operator>>(istream &fct,nevertebrata &ob)
{
    regn *aux;
    try{
    aux=dynamic_cast<regn*>(&ob);}
    catch(bad_cast){cout<<"dynamic cast nereusit";}
    cin>>*aux;
    ob=static_cast <nevertebrata&>(*aux);
    double x,y;
    int e;
    cout<<"Lungime: ";
    fct>>x;
    cout<<"Greutate: ";
    fct>>y;
    cout<<"Durata viata: ";
    fct>>e;
    ob.set_nev(x,y,e);
return fct;
}

ostream& operator<<(ostream &fct,nevertebrata &ob)
{
ob.afisare();
return fct;

}

nevertebrata& nevertebrata::operator=(const nevertebrata&a)
{ nume=a.nume;
    den_st=a.den_st;
    specie=a.specie;
    lungime=a.lungime;
    greutate=a.greutate;
    med_viata=a.med_viata;
    durata_viata=a.durata_viata;
    return *this;

}

void nevertebrata::afisare()
{
    cout<<"Nevertebrata:"<<endl<<endl<<"Nume:"<<nume<<endl<<"Denumire stiintifica: "<<den_st<<endl<<"Specie: "<<specie<<endl<<"Mediu viata: "<<med_viata<<endl<<"Lungime: "<<lungime<<endl<<"Greutate: "<<greutate<<endl<<"Durata viata: "<<durata_viata<<endl<<endl;
}

nevertebrata::nevertebrata(const nevertebrata &a)
{
    nume=a.nume;
    den_st=a.den_st;
    specie=a.specie;
    lungime=a.lungime;
    greutate=a.greutate;
    med_viata=a.med_viata;
    durata_viata=a.durata_viata;
}

class vertebrata:public regn
{
protected:
    int nr_vertebre;
    string reg;

public:
    vertebrata(){};
    vertebrata(string a,string b,string c,string f,int x,string q):regn(a,b,c,f){nr_vertebre=x; reg=q;};
    ~vertebrata(){cout<<"dist vert";};
    vertebrata(const vertebrata&);

    friend istream& operator>>(istream &,vertebrata &);
    friend ostream& operator<<(ostream &,vertebrata &);
    vertebrata& operator=(const vertebrata&);

    void set_v(int x,string r){nr_vertebre=x; reg=r;};
    void afisare();
    //virtual void afisare()=0;

};

istream& operator>>(istream &fct,vertebrata &ob)
{
    regn*aux;
    try{
    aux=dynamic_cast<regn*>(&ob);}
    catch(bad_cast){cout<<"dynamic cast nereusit";}
    cin>>*aux;
    ob=static_cast <vertebrata&>(*aux);
    int x;
    string r;
    cout<<"Numar vertebre: ";
    fct>>x;
    cout<<"Regim(Carnivor/Omnivor/Erbivor): ";
    fct>>r;

    ob.set_v(x,r);
    return fct;

}

ostream& operator<<(ostream &fct,vertebrata &ob)
{
ob.afisare();
return fct;

}
vertebrata& vertebrata::operator=(const vertebrata&a)
{ nume=a.nume;
    den_st=a.den_st;
    specie=a.specie;
    nr_vertebre=a.nr_vertebre;
    reg=a.reg;
    return *this;

}

void vertebrata::afisare()
{  cout<<"Vertebrata:"<<endl<<endl<<"Nume:"<<nume<<endl<<"Denumire stiintifica: "<<den_st<<endl<<"Specie: "<<specie<<endl<<"Mediu viata: "<<med_viata<<endl<<"Numar vertebre: "<<nr_vertebre<<endl<<"Regim: "<<reg<<endl<<endl;
}

vertebrata::vertebrata(const vertebrata &a)
{
    nume=a.nume;
    den_st=a.den_st;
    specie=a.specie;
    med_viata=a.med_viata;
    nr_vertebre=a.nr_vertebre;
    reg=a.reg;
}

class peste:public vertebrata
{
protected:
    string apa;
    string schelet;
public:
      peste(){};
      peste(string a,string b,string c,int e,string f,string g,string h):vertebrata(a,b,c,"Acvatic",e,f){apa=g; schelet=h;};
      ~peste(){};
      peste(const peste&);

      friend istream& operator>>(istream&,peste&);
      friend ostream& operator<<(ostream&,peste&);
      peste& operator=(const peste&);

      void afisare();

};

peste& peste::operator=(const peste &a)
{
    nume=a.nume;
    specie=a.specie;
    den_st=a.den_st;
    med_viata=a.med_viata;
    nr_vertebre=a.nr_vertebre;
    reg=a.reg;

    apa=a.apa;
    schelet=a.schelet;
    return *this;
}


peste::peste(const peste&a)
{
    nume=a.nume;
    den_st=a.den_st;
    med_viata=a.med_viata;
    specie=a.specie;
    nr_vertebre=a.nr_vertebre;
    reg=a.reg;

    apa=a.apa;
    schelet=a.schelet;

}

istream& operator>>(istream &fct, peste &ob)
{
    vertebrata *aux;
    try{
    aux=dynamic_cast<vertebrata*>(&ob);}
    catch(bad_cast){cout<<"dynamic cast nereusit";}
    cin>>*aux;
    ob=static_cast <peste&>(*aux);

    cout<<"Tip apa(sarata/dulce/ambele): ";
    fct>>ob.apa;
    cout<<"Tip schelet(os/cartilaj): ";
    fct>>ob.schelet;
    return fct;
}

void peste::afisare()
{ cout<<"Peste:"<<endl<<endl<<"Nume: "<<nume<<endl<<"Denumire stiintifica: "<<den_st<<endl<<"Specie: "<<specie<<endl<<"Mediu viata: "<<med_viata<<endl<<"Numar vertebre: "<<nr_vertebre<<endl<<"Regim: "<<reg<<endl<<"Tip apa(sarata/dulce/ambele): "<<apa<<endl<<"Tip schelet(os/cartilaj): "<<schelet<<endl<<endl;
}

ostream& operator<<(ostream &fct, peste &ob)
{
    ob.afisare();
    return fct;
}

class pasare:public vertebrata
{
protected:
    string tip;
    string act;
public:
      pasare(){};
      pasare(string a,string b,string c,string d,int e,string f,string g,string h):vertebrata(a,b,c,d,e,f){tip=g; act=h;};
      ~pasare(){};
      pasare(const pasare&);

      friend istream& operator>>(istream&,pasare&);
      friend ostream& operator<<(ostream&,pasare&);
      pasare& operator=(const pasare&);

      void afisare();

};

pasare& pasare::operator=(const pasare &a)
{
    nume=a.nume;
    specie=a.specie;
    den_st=a.den_st;
    med_viata=a.med_viata;
    nr_vertebre=a.nr_vertebre;
    reg=a.reg;

    tip=a.tip;
    act=a.act;
    return *this;
}

pasare::pasare(const pasare&a)
{
    nume=a.nume;
    den_st=a.den_st;
    med_viata=a.med_viata;
    specie=a.specie;
    nr_vertebre=a.nr_vertebre;
    reg=a.reg;

    tip=a.tip;
    act=a.act;

}

istream& operator>>(istream &fct, pasare &ob)
{
    vertebrata *aux;
    try{
    aux=dynamic_cast<vertebrata*>(&ob);}
    catch(bad_cast){cout<<"dynamic cast nereusit";}
    cin>>*aux;
    ob=static_cast <pasare&>(*aux);
    cout<<"Diurna/Nocturna: ";
    fct>>ob.act;
    cout<<"Domestica/Migratoare: ";
    fct>>ob.tip;
    return fct;
}

void pasare::afisare()
{  cout<<"Pasare:"<<endl<<endl<<"Nume: "<<nume<<endl<<"Denumire stiintifica: "<<den_st<<endl<<"Specie: "<<specie<<endl<<"Mediu viata: "<<med_viata<<endl<<"Numar vertebre: "<<nr_vertebre<<endl<<"Regim: "<<reg<<endl<<"Diurna/Nocturna"<<act<<endl<<"Domestica/Migratoare: "<<tip<<endl<<endl;
}

ostream& operator<<(ostream &fct, pasare &ob)
{
    ob.afisare();
    return fct;
}

class mamifer:public vertebrata
{
protected:
    int nr_pui;
    string tip;
    string repr;

public:
      mamifer(){};
      mamifer(string a,string b,string c,string d,int e,string f,int z,string g,string h):vertebrata(a,b,c,d,e,f){nr_pui=z; tip=g; repr=h;};
      ~mamifer(){};
      mamifer(const mamifer&);

      friend istream& operator>>(istream&,mamifer&);
      friend ostream& operator<<(ostream&,mamifer&);
      mamifer& operator=(const mamifer&);

      void afisare();

};

mamifer& mamifer::operator=(const mamifer &a)
{
    nume=a.nume;
    specie=a.specie;
    den_st=a.den_st;
    med_viata=a.med_viata;
    nr_vertebre=a.nr_vertebre;
    reg=a.reg;

    nr_pui=a.nr_pui;
    tip=a.tip;
    repr=a.repr;
    return *this;
}

mamifer::mamifer(const mamifer&a)
{
    nume=a.nume;
    den_st=a.den_st;
    med_viata=a.med_viata;
    specie=a.specie;
    nr_vertebre=a.nr_vertebre;
    reg=a.reg;

    nr_pui=a.nr_pui;
    tip=a.tip;
    repr=a.repr;

}

istream& operator>>(istream &fct, mamifer &ob)
{
    vertebrata *aux;
    try{
    aux=dynamic_cast<vertebrata*>(&ob);}
    catch(bad_cast){cout<<"dynamic cast nereusit";}
    cin>>*aux;
    ob=static_cast <mamifer&>(*aux);
    cout<<"Tip reproducere(Ovifer/Marsupial/Placentar): ";
    fct>>ob.repr;
    cout<<"Numar pui: ";
    fct>>ob.nr_pui;
    cout<<"Domestic/Salbatic: ";
    fct>>ob.tip;

    return fct;
}

void mamifer::afisare()
{   cout<<"Mamifer:"<<endl<<endl<<"Nume: "<<nume<<endl<<"Denumire stiintifica: "<<den_st<<endl<<"Specie: "<<specie<<endl<<"Mediu viata: "<<med_viata<<endl<<"Numar vertebre: "<<nr_vertebre<<endl<<"Regim: "<<reg<<endl<<"Tip reproducere: "<<repr<<endl<<"Numar pui: "<<nr_pui<<endl<<"Domestic/Salbatic: "<<tip<<endl<<endl;
}

ostream& operator<<(ostream &fct, mamifer &ob)
{
    ob.afisare();
    return fct;
}


class reptila:public vertebrata
{
protected:
    string clasif;
    string depl;
    string repr;

public:
      reptila(){};
      reptila(string a,string b,string c,string d,int e,string f,string g,string h):vertebrata(a,b,c,d,e,f){depl=g; clasif=h;};
      ~reptila(){};
      reptila(const reptila&);

      friend istream& operator>>(istream&,reptila&);
      friend ostream& operator<<(ostream&,reptila&);
      reptila& operator=(const reptila&);

      void afisare();

};

reptila& reptila::operator=(const reptila &a)
{
    nume=a.nume;
    specie=a.specie;
    den_st=a.den_st;
    med_viata=a.med_viata;
    nr_vertebre=a.nr_vertebre;
    reg=a.reg;

    clasif=a.clasif;
    depl=a.depl;
    return *this;
}


reptila::reptila(const reptila&a)
{
    nume=a.nume;
    den_st=a.den_st;
    med_viata=a.med_viata;
    specie=a.specie;
    nr_vertebre=a.nr_vertebre;
    reg=a.reg;

    clasif=a.clasif;
    depl=a.depl;

}

istream& operator>>(istream &fct, reptila &ob)
{
    vertebrata *aux;
    try{
    aux=dynamic_cast<vertebrata*>(&ob);}
    catch(bad_cast){cout<<"dynamic cast nereusit";}
    cin>>*aux;
    ob=static_cast <reptila&>(*aux);

    cout<<"Tip(Crocodil/Testoasa/Scuamata/Tuatare): ";
    fct>>ob.clasif;
    cout<<"Deplasare(Taratoare/Picioare): ";
    fct>>ob.depl;

    return fct;
}

void reptila::afisare()
{   cout<<"Reptila: "<<endl<<endl<<"Nume: "<<nume<<endl<<"Denumire stiintifica: "<<den_st<<endl<<"Specie: "<<specie<<endl<<"Mediu viata: "<<med_viata<<endl<<"Numar vertebre: "<<nr_vertebre<<endl<<"Regim: "<<reg<<endl<<"Tip: "<<clasif<<endl<<"Deplasare: "<<depl<<endl<<endl;

}

ostream& operator<<(ostream &fct, reptila &ob)
{
    ob.afisare();
    return fct;
}




template <class T> class AtlasZoologic
{
    int nr_animale;
    regn **animale;
public:
    AtlasZoologic(){nr_animale=0;};
    AtlasZoologic(int a){
        try{
        animale=new regn*[a]; nr_animale=0;
        }catch(bad_alloc xa)
        {
            cout<<"Alocare esuata\n";
        };
       };
    AtlasZoologic<T>& operator+=(T&);
    AtlasZoologic<T>& operator=(AtlasZoologic<T>&);
    void afisare(){for(int i=0;i<nr_animale;i++)
    animale[i]->afisare();
    }

    ~AtlasZoologic(){
    for(int i=0;i<nr_animale;i++)
        delete animale[i];
    delete animale;
    };
};

template <class T>
AtlasZoologic<T>& AtlasZoologic<T>:: operator+=(T &a)
{
    try{
    animale[nr_animale]=new T;}
    catch(bad_alloc xa)
    {
        cout<<"Alocare nereusita/n";
    };
        animale[nr_animale]=&a;
        nr_animale++;

    return *this;
}


template <class T>
AtlasZoologic<T>& AtlasZoologic<T>:: operator=(AtlasZoologic<T> &a)
{
    if(nr_animale!=a.nr_animale)
    {
        for(int i=0;i<nr_animale;i++)
            delete animale[i];
    delete animale;
    }

    nr_animale=a.nr_animale;
    for(int i=0;i<nr_animale;i++)
        animale[i]=a.animale[i];
    return (*this);

}

template <> class AtlasZoologic <nevertebrata>
{
    int nr_nev;
    nevertebrata **animale;
public:
    AtlasZoologic(){nr_nev=0;};
    AtlasZoologic& operator++(){nr_nev++;  return *this;};
    void afisare_nrnev(){cout<<"Numar nevertebrate="<<nr_nev<<endl;};


    AtlasZoologic(int a){
        try{
        animale=new nevertebrata*[a]; nr_nev=0;
        }catch(bad_alloc xa)
        {
            cout<<"Alocare esuata\n";
        };
       };
    AtlasZoologic<nevertebrata>& operator+=(nevertebrata&);
    AtlasZoologic<nevertebrata>& operator=(AtlasZoologic<nevertebrata>&);
    void afisare(){for(int i=0;i<nr_nev;i++)
    animale[i]->afisare();
    }

    ~AtlasZoologic(){
    for(int i=0;i<nr_nev;i++)
        delete animale[i];
    delete animale;
    };
};


AtlasZoologic<nevertebrata>& AtlasZoologic<nevertebrata>:: operator+=(nevertebrata &a)
{
    try{
    animale[nr_nev]=new nevertebrata;}
    catch(bad_alloc xa)
    {
        cout<<"Alocare nereusita/n";
    };
        animale[nr_nev]=&a;
        nr_nev++;

    return *this;
}


AtlasZoologic<nevertebrata>& AtlasZoologic<nevertebrata>:: operator=(AtlasZoologic<nevertebrata> &a)
{
    if(nr_nev!=a.nr_nev)
    {
        for(int i=0;i<nr_nev;i++)
            delete animale[i];
    delete animale;
    }

    nr_nev=a.nr_nev;
    for(int i=0;i<nr_nev;i++)
        animale[i]=a.animale[i];
    return (*this);

}




int main()
{

  cout<<"Numar animale:";
  int n;
  cin>>n;
  int act;
  AtlasZoologic<regn> a(n);
  AtlasZoologic<nevertebrata> b;
for(int i=0;i<n;i++)
  {
      if(i==0)
      {cout<<"Inserare nevertebrata:1\n";
      cout<<"Inserare mamifer:2\n";
      cout<<"Inserare pasare:3\n";
      cout<<"Inserare peste:4\n";
      cout<<"Inserare reptila:5\n";}
        cout<<"Tip animal "<<i+1<<": ";
      cin>>act;

      if(act==1)
        {

            nevertebrata *aux;
            aux=new nevertebrata;
            cin>>(*aux);

            a+=(*aux);
            ++b;
        }
      if(act==2)
      {
          mamifer *aux;
          aux=new mamifer;
          cin>>(*aux);

          a+=(*aux);

      }
      if(act==3)
      {
          pasare *aux;
          aux=new pasare;
          cin>>(*aux);

          a+=(*aux);


      }
      if(act==4)
      {
          peste *aux;
          aux=new peste;
          cin>>(*aux);

          a+=(*aux);

      }
      if(act==5)
      {
          reptila *aux;
          aux=new reptila;
          cin>>(*aux);

          a+=(*aux);
      }}


cout<<"Atlas:\n\n";
a.afisare();
        cout<<endl;
       b.afisare_nrnev();
       cout<<endl;







    return 0;
}
