#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

class Team
{
	public:
		 string name;
		 float quality;
		 int points;
		int form;
		  void wykonajOperacje( string nazwa1, std::string nazwa2, int jakosc )
{
	points=0;
	form=0;
   
   name= nazwa1 + " " +nazwa2;
   quality= jakosc;
   cout<<name<<" "<<quality<<" "<<endl;
}

	
	
};


class Match
{
	public:
	
	static void Play(Team* Team1, Team* Team2)
	{
		if(rand()%100<50+(Team1->quality+Team1->form-Team2->quality-Team2->form))
	{
		Team1->points+=3;
		Team1->form++;
		Team2->form--;
	}
	else if(rand()%100<50+(Team2->quality+Team2->form-Team1->quality-Team1->form))
	{
		Team2->points+=3;
		Team2->form++;
		Team1->form--;
	}
	
	else
	{
	 Team1->points++;
	 Team2->points++;
	}	
	}
};

class Season
{
	public:
	static void Weeks (Team table[])
	{
		for (int round = 0; round < 38; round++)
		{
			
			for (int match = 0; match < 10; match++)
			{
				int n = 20 - 1;
				int home = (round + match)%n;
				int away = (round - match + n)%n;
				if (match == 0)
					away = 20 - 1;
				if (round%2)
					std::swap(home, away);
				
				Match::Play(&table[home], &table[away]);
				
			}
		}
	}

	
	
};




int main()
{
	srand(time(NULL));
	string l;
	cout<<"Wybierz ktora lige chcesz symulowac: "<<endl;
	cout<<"Wybierz 1 Ekstraklasa"<<endl;
	cout<<"Wybierz 2 Bundesliga"<<endl;
	cout<<"Wybierz 3 Premier League"<<endl;
	cout<<"Wybierz 4 La Liga"<<endl;
	cout<<"Wybierz 5 Seria A "<<endl;
	
	cin>>l;
	string k=l+".txt";
	
	
	string nazwaPliku=k;
	
	std::ifstream plik;
    plik.open( nazwaPliku.c_str() );
    if( !plik.good() )
         return false;
	
     Team tablica[20];

    for(int i=0;i<20;i++) 
    {
        string a;
        std::string b;
        int c;
        plik >> a >> b >> c;
      
             tablica[i].wykonajOperacje( a, b, c );
        
    }
	
 	Season::Weeks(tablica);
    
     cout << "po sezonie" << endl << endl;;
     for (int i = 0; i < 20; i++)
     	for(int j = 0; j < 20; j++)
		 {
		 	if (tablica[i].points > tablica[j].points)
		 		swap(tablica[i], tablica[j]);
		 }
		 
		 for (int i = 0; i < 20;i++)
     	cout << tablica[i].name << " " << tablica[i].points <<"pkt"<< endl;
     
    return 0;
}