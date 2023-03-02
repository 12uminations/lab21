#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<iomanip>
using namespace std;

class Unit{
        string type;
        int hpmax;
        int atk;
        int def;
        string move1;
        string move1type;
        int move1atk;
        string move2;
        string move2type;
        int move2atk;
        string move3;
        string move3type;
        int move3atk;
        string move4;//protect
        bool protect_on;
    public:
        string name;
        int hp;
        int spe;
        Unit(string,string,int,int,int,int,int,string,string,int,string,string,int,string,string,int,string,bool);
		vector<int> getSelect();
        vector<string> getSelect2();
        vector<string> getSelect3();
        vector<int> getSelect4();
        void choose(Unit *);
		void showStatusforP1();
		void showStatusforP2();
		void newTurn();
		int attack(Unit &,int);
		int beAttacked(int,string,int);
		int heal();	
		bool isDead();
};
int Unit::beAttacked(int oppatk,string movetype,int moveatk){
    double dmg;
    if(protect_on) dmg = 0;
    else{
        if(movetype == "Fire"){
            if(type == "Grass") dmg = (moveatk+oppatk-def)*2;
            else if (type == "Ice") dmg = (moveatk+oppatk-def)*2;
            else if (type == "Fire") dmg = (moveatk+oppatk-def)/2;
            else if (type == "Water") dmg = (moveatk+oppatk-def)/2;
        }
        else if(movetype == "Grass"){
            if(type == "Water") dmg = (moveatk+oppatk-def)*2;    
            else if (type == "Ice") dmg = (moveatk+oppatk-def)/2;
            else if (type == "Grass") dmg = (moveatk+oppatk-def)/2;
            else if (type == "Fire") dmg = (moveatk+oppatk-def)/2;
            else if (type == "Fairy") dmg = (moveatk+oppatk-def)*2;
            else if (type == "Fighting") dmg = (moveatk+oppatk-def)*2;
        }
        else if(movetype == "Water"){
            if(type == "Fire") dmg = (moveatk+oppatk-def)*2;    
            else if (type == "Grass") dmg = (moveatk+oppatk-def)/2;
            else if (type == "Water") dmg = (moveatk+oppatk-def)/2;
        }
        else if(movetype == "Fighting"){
            if(type == "Normal") dmg = (moveatk+oppatk-def)*2;    
            else if (type == "Ghost") dmg = 0;
            else if (type == "Ice") dmg = (moveatk+oppatk-def)*2;
            else if (type == "Dark") dmg = (moveatk+oppatk-def)*2;
            else if (type == "Fighting") dmg = (moveatk+oppatk-def)/2;
            else if (type == "Grass") dmg = (moveatk+oppatk-def)/2;
            else if (type == "Fairy") dmg = (moveatk+oppatk-def)/2;
        }
        else if(movetype == "Dragon"){
            if(type == "Dragon") dmg = (moveatk+oppatk-def)*2;    
            else if (type == "Fairy") dmg = 0;
        }
        else if(movetype == "Ice"){
            if(type == "Dragon") dmg = (moveatk+oppatk-def)*2;
            else if (type == "Grass") dmg = (moveatk+oppatk-def)*2;
            else if (type == "Water") dmg = (moveatk+oppatk-def)/2;
            else if (type == "Fire") dmg = (moveatk+oppatk-def)/2;
            else if (type == "Ice") dmg = (moveatk+oppatk-def)/2;
        }
        else if(movetype == "Dark"){
            if(type == "Ghost") dmg = (moveatk+oppatk-def)*2;    
            else if (type == "Fighting") dmg = (moveatk+oppatk-def)/2;
        }
        else if(movetype == "Ghost"){
            if(type == "Ghost") dmg = (moveatk+oppatk-def)*2;    
            else if (type == "Normal") dmg =0;
            else if (type == "Dark") dmg = (moveatk+oppatk-def)/2;
        }
        else if(movetype == "Fairy"){
            if(type == "Fighting") dmg = (moveatk+oppatk-def)*2;    
            else if (type == "Dark") dmg = (moveatk+oppatk-def)*2;
            else if (type == "Dragon") dmg = (moveatk+oppatk-def)*2;
            else if (type == "Fire") dmg = (moveatk+oppatk-def)/2;
            else if (type == "Grass") dmg = (moveatk+oppatk-def)/2;
        }
        else if(movetype == "Normal"){
            if(type == "Ghost") dmg = 0;    
        }
    }
    
    hp -= dmg;
	if(hp <= 0) hp = 0;
	
	return dmg;	
}
int Unit::attack(Unit &x,int y){
    if(y==1) return x.beAttacked(atk,move1type,move1atk);
    else if(y==2) return x.beAttacked(atk,move2type,move2atk);
    else if(y==3) return x.beAttacked(atk,move3type,move3atk); 
}
Unit::Unit(string a,string b,int c,int d,int e,int q,int r,string f,string g,int h,string i,string j,int k,string l,string m,int n,string o,bool p){
    name = a;
    type = b;
    hpmax = c;
    atk = d;
    def = e;
    spe = q;
    hp = r;
    move1 =f;
    move1type =g;
    move1atk =h;
    move2 = i;
    move2type = j;
    move2atk = k;
    move3 = l;
    move3type = m;
    move3atk = n;
    move4 = o;
    protect_on = p;
}

vector<string> Unit::getSelect2(){
    vector<string> s;
     s.push_back(name);
     s.push_back(type);
     return s;
}
vector<int> Unit::getSelect(){
    vector<int> x;
     x.push_back(hpmax);
     x.push_back(atk);
     x.push_back(def);
     x.push_back(spe);
     return x;
}
vector<string> Unit::getSelect3(){
    vector<string> s;
     s.push_back(move1);
     s.push_back(move1type);
     s.push_back(move2);
     s.push_back(move2type);
     s.push_back(move3);
     s.push_back(move3type);
     s.push_back(move4);
     return s;
}
vector<int> Unit::getSelect4(){
    vector<int> x;
     x.push_back(move1atk);
     x.push_back(move2atk);
     x.push_back(move3atk);
     return x;
}
int Unit::heal(){
    int h=60;
	if(hp + h > hpmax) h = hpmax - hp;
	hp = hp + h;
	return h;
}	
void Unit::showStatusforP1(){
		cout << "Player1--------------------------------\n"; 
		cout << name << "\n"; 
		cout << "HP: " << hp << "/" << hpmax << "\tATK: "<< atk << "\t\tDEF: "<< def;		
		cout << "\n---------------------------------------\n";
    }
void Unit::showStatusforP2(){
		cout << "\t\t\t\tPlayer2--------------------------------\n"; 
		cout << "\t\t\t\t" << name << "\n"; 
		cout << "\t\t\t\tHP: " << hp << "/" << hpmax<< "\t\tATK: "<< atk << "\t\tDEF: "<< def;
		cout << "\n\t\t\t\t---------------------------------------\n";
	}
void ChoosePokemon(vector<Unit> &y,string x[],Unit a,Unit b,Unit c,Unit d,Unit e,Unit f,Unit g,Unit h,Unit i,Unit j){
    cout<<"-----Choose your first pokemon----- " <<endl;
    cout<<"Input Number to choose : ";
    while (y.size() < 3) {
        int pokemonIndex;
        cin >> pokemonIndex;

    bool alreadyChosen = false;
    for (int i = 0; i < y.size(); i++) {
        if (y[i].name == x[pokemonIndex-1]) {
            alreadyChosen = true;
            break;
        }
    }
    if (alreadyChosen) {
        cout << "That Pokemon has already been selected. Please choose a different one." << endl ;
        cout << "Please select your next Pokemon agian: " ;
        continue;
    }
        switch (pokemonIndex) {
        case 1:
            y.push_back(a);
            break;
        case 2:
            y.push_back(b);
            break;
        case 3:
            y.push_back(c);
            break;
        case 4:
            y.push_back(d);
            break;
        case 5:
            y.push_back(e);
            break;
        case 6:
            y.push_back(f);
            break;
        case 7:
            y.push_back(g);
            break;
        case 8:
            y.push_back(h);
            break;
        case 9:
            y.push_back(i);
            break;
        case 10:
            y.push_back(j);
            break;
        
        default:
            cout << "Invalid Pokemon selection. Please choose a valid option." << endl;
            continue;
    }
    if (y.size() < 3) {
        cout << "Please select your next Pokemon: " ;
    } else {
        break;
    }
    
    }
    cout << "-----You have selected the following Pokemon----- " << endl;
        for (int i = 0; i < y.size(); i++) {
    cout <<i+1 <<"."<< y[i].name<< endl;
    }
}
void P1_Team(vector<Unit> &x){
    cout<<"Your Current Pokemon : " <<"1." <<x[0].name <<endl;
    cout<<"Your Other Pokemon : " ;
    for(int i = 0 ; i < 3 ; i++){
        if(x[i].name != x[0].name){
            cout<<i+1<<"." <<x[i].name <<" ";
        }
   }
   cout<<endl;
}

void Switch(vector<Unit> &x){
    cout<<"Switch The Current Pokemon : "  ;
    int Switch_Number ;
    cin >> Switch_Number ;
    Unit temp = x[0] ;
    x[0] = x[Switch_Number-1] ;
    x[Switch_Number-1] = temp;
}
void showpk(vector<Unit> x){
    for(int i = 0 ; i < 10  ;i++){
        cout << i+1<<".";
        for(int j = 0 ; j < 2 ;j++){
        	vector<string> stat = x[i].getSelect2();
        	cout  << stat[j]<< " ";
        }
        cout<<" ";
        for(int k = 0 ; k < 1 ;k++){
           vector<int> stat2 = x[i].getSelect();
            cout << "HP" <<stat2[k]<< " "<< "ATK" <<stat2[k+1]<< " "<< "DEF"<< stat2[k+2]<< " "<< "SPEED"<< stat2[k+3]<< " "; 
        }
		for(int l = 0 ; l < 7 ;l+=2){
        	vector<string> stat3 = x[i].getSelect3();
        	cout  << stat3[l];
        	if(l<6) cout<<" Type:"<<stat3[l+1]<<" ";
        }
        cout<<endl;
    }
}
void swpoP(int x,vector<Unit> a){
    if(x==0){
        P1_Team(a);
        cout<<"---------------------------------------\n";
        Switch(a); 
        cout<<"---------------------------------------\n";
        P1_Team(a);
        cout<<"---------------------------------------\n";
    }
    if(x==5) a[0].heal();
}
void speedf(int x,int y,vector<Unit> a,vector<Unit> b){
    if(a[0].spe > b[0].spe){
        a[0].attack(b[0],x);
        if(b[0].hp!=0) b[0].attack(a[0],y);
        // else if(b[0].hp==0){
        //     P1_Team(b);
        //     cout<<"---------------------------------------\n";
        //     Switch(b); 
        //     cout<<"---------------------------------------\n";
        //     P1_Team(b);
        //     cout<<"---------------------------------------\n";
        // }
        }
    else{
        b[0].attack(a[0],y);
        if(a[0].hp!=0) a[0].attack(b[0],x);
        // else if(a[0].hp==0){
        //     P1_Team(a);
        //     cout<<"---------------------------------------\n";
        //     Switch(a); 
        //     cout<<"---------------------------------------\n";
        //     P1_Team(a);
        //     cout<<"---------------------------------------\n";
        // }
    }
}

int main(){  
    Unit poke1 ("Charizard","Fire",200,50,50,100,200,"Daimonji","Fire",75,"DragonClaw","Dragon",50,"BrickBreak","Fighting",50,"Protect",false);
	Unit poke2 ("Blastoise","Water",200,25,75,78,200,"HydroPump","Water",75,"DarkPaluse","Dark",50,"IceBeam","Ice",50,"Protect",false);
	Unit poke3 ("Venusaur","Grass",200,25,75,80,200,"SolarBeam","Grass",75,"SeedBomb","Grass",65,"Doube-Edge","Normal",60,"Protect",false);
	Unit poke4 ("Snorlax","Normal",400,10,30,30,400,"HyperBeam","Normal",90,"Crunch","Dark",50,"HammerArm","Fighting",50,"Protect",false);
	Unit poke5 ("Lucario","Fighting",175,75,50,90,175,"CloseCombat","Fighting",75,"DragonPaluse","Dragon",50,"ExtreamSpeed","Normal",60,"Protect",false);
	Unit poke6 ("Gengar","Ghost",200,75,25,110,200,"DestinyBond","Ghost",75,"SukerPunch","Dark",50,"FirePunch","Fire",50,"Protect",false);
	Unit poke7 ("Gardevoir","Fairy",200,75,25,85,200,"Moonblast","Fairy",75,"MysticalFire","Fire",50,"GrassKnot","Grass",50,"Protect",false);
	Unit poke8 ("Garchomp","Dragon",200,50,50,102,200,"DragonRush","Dragon",75,"BrickBreak","Fighting",50,"FireFang","Fire",50,"Protect",false);
	Unit poke9 ("Abomasnow","Ice",300,30,30,60,300,"Blizzard","Ice",75,"WoodHammer","Grass",60,"IcePunch","Ice",50,"Protect",false);
	Unit poke10 ("Absol","Dark",200,60,40,75,200,"NightSlash","Dark",75,"Curse","Ghost",50,"RockSmash","Fighting",50,"Protect",false);

    vector<Unit> player1_pokemon = {poke1, poke2, poke3};
    vector<Unit> allpoke = {poke1, poke2, poke3,poke4,poke5,poke6,poke7,poke8,poke9,poke10};
     string pokemonNames[] = {"Charizard","Blastoise","Venusaur","Snorlax","Lucario","Gengar","Gardevoir","Garchomp","Abomasnow","Absol",};
    ////////////////////////////////////////////////////
    vector<Unit> selected_pokemon1; //Arrey โปเกมอน;
    vector<Unit> selected_pokemon2; //Arrey โปเกมอน
    int sd=1;
    showpk(allpoke);
    ////////////////////////////////////////////////////
        cout<<"---------------------------------------\n";//เลือกโปร
        cout<<"Player_1 Team Selection\n";
        ChoosePokemon(selected_pokemon1,pokemonNames,poke1,poke2,poke3,poke4,poke5,poke6,poke7,poke8,poke9,poke10);
        cout<<"---------------------------------------\n";//เลือกโ
        cout<<"Player_2 Team Selection\n";
        ChoosePokemon(selected_pokemon2,pokemonNames,poke1,poke2,poke3,poke4,poke5,poke6,poke7,poke8,poke9,poke10);
        cout<<"---------------------------------------\n";//เลือกโปรแกมอน
    while(true){
        selected_pokemon2[0].showStatusforP2();
        selected_pokemon1[0].showStatusforP1();
		char player1_action;
		char player2_action;
		int num1;
		int num2;
		cout<<"['F' Fight] ['S' Switch] ['H' Heal] What will Player1 do?  ";
		cin>> player1_action;
		player1_action = toupper(player1_action);
		if(player1_action=='F'){
		    int i = 0;
			for(int l = 0 ; l < 7 ;l+=2){
				vector<string> stat3 = selected_pokemon1[0].getSelect3();
				cout <<i+1 <<"."<< stat3[l];
				vector<int> stat4 = selected_pokemon1[0].getSelect4();
				if(l<6) cout<<" MoveDamage:"<<stat4[i];
				if(l<6) cout<<" Type:"<<stat3[l+1]<<"\n";
				i++;
            }
            cout<<endl; 
            cout<<"What move will your Copymon use? ";
            cin>>num1;
            //if(num == 1) selected_pokemon1[0].();
		}
	    else if(player1_action=='H') selected_pokemon1[0].heal();
	    else if(player1_action == 'S'){
	        
	    }
	   cout<<"['F' Fight] ['S' Switch] ['H' Heal] What will Player2 do?  ";
		cin>> player2_action;
		player2_action = toupper(player2_action);
		if(player2_action=='F'){
		    int i = 0;
			for(int l = 0 ; l < 7 ;l+=2){
				vector<string> stat3 = selected_pokemon2[0].getSelect3();
				cout <<i+1 <<"."<< stat3[l];
				vector<int> stat4 = selected_pokemon2[0].getSelect4();
				if(l<6) cout<<" MoveDamage:"<<stat4[i];
				if(l<6) cout<<" Type:"<<stat3[l+1]<<"\n";
				i++;
            }
            cout<<endl; 
            cout<<"What move will your Copymon use? ";
            cin>>num2;
		}
	    else if(player2_action=='H') num2=5;
	    else if(player2_action == 'S') num2 = 0;
	    swpoP(num1,selected_pokemon1);
	    swpoP(num2,selected_pokemon2);
	    speedf(num1,num2,selected_pokemon1,selected_pokemon2);
	    
}
}
