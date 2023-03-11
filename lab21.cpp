#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<iomanip>

using namespace std;

class Unit{
		string name;
		string type;		
		int hp;
		int hpmax;
		int atk;
		int def;
		bool guard_on;		
	public:			
		void create(string);
		void showStatus();
		void newTurn();
		int attack(Unit &);
		int beAttacked(int);
		int heal();	
		void guard();
		bool isDead();	
};

void Unit::create(string t){ 
	if(t == "Hero"){
		type = "Hero";
		cout << "Please input your name: ";
		getline(cin,name);
		hpmax = rand()%20+90;
		atk = rand()%5+14;
		def = rand()%3+9;
	}else if(t == "Monster"){
		type = "Monster";
		name = "Kraken";
		hpmax = rand()%20+200;
		atk = rand()%5+25;
		def = rand()%3+5;
	}
	hp = hpmax;
	guard_on = false;
}

void Unit::showStatus(){
	if(type == "Hero"){
		cout << "---------------------------------------\n"; 
		cout << name << "\n"; 
		cout << "HP: " << hp << "/" << hpmax << "\tATK: "<< atk << "\t\tDEF: "<< def;		
		cout << "\n---------------------------------------\n";
	}	
	else if(type == "Monster"){
		cout << "\t\t\t\t---------------------------------------\n"; 
		cout << "\t\t\t\t" << name << "\n"; 
		cout << "\t\t\t\tHP: " << hp << "\t\tATK: "<< atk << "\t\tDEF: "<< def;
		cout << "\n\t\t\t\t---------------------------------------\n";
	}
}

void Unit::newTurn(){
	guard_on = false;
}



bool Unit::isDead(){
    if(hp <= 0) return true;
    else return false;
}
void Unit::guard(){
    guard_on = true;
}
int Unit::beAttacked(int oppatk){
    double dmg;
    if(guard_on==false){
        dmg = oppatk-def;
        hp=hp-dmg;
        return dmg;
    }
    else{
        dmg=(oppatk-def)/3;
        hp=hp-dmg;
        return dmg;
    }
}
int Unit::attack(Unit &x){
	return x.beAttacked(atk);
}
int Unit::heal(){
    int y; 
    int x = rand()%21+10;
    if(hp+x > hpmax){
        y = hpmax-hp;
        hp = hpmax;
        return y;
    }
    else {
        hp = hp+x;
        return x;
        }
}



void drawScene(char p_action,int p,char m_action,int m){
	cout << "                                                       \n";
	if(p_action == 'A'){
	cout << "                                       "<< -p <<"\n";
	}else{
	cout << "                                                       \n";	
	}	
	cout << "                                *               *      \n";
	cout << "                                **  *********  **      \n";
	cout << "                                ****         ****      \n";
	if(m_action == 'A'){
	cout << "                 " << setw(5) << -m << "           *** **   ** ***       Attack!\n";
	}else if(m_action == 'G'){
	cout << "                                 *** **   ** ***       Guard!\n";
	}else{
	cout << "                                 *** **   ** ***       \n";	
	}
	cout << "                                  ** **   ** **        \n";
	cout << "                   ***             *         *         \n";
	if(p_action == 'A'){
	cout << "        Attack!    ***  *           *********          \n";		
	}else if(p_action == 'H'){
	cout << "      Heal! +" << setw(2) << p << "    ***  *           *********          \n";
	}else if(p_action == 'G'){
	cout << "         Guard!    ***  *           *********          \n";
	}else{
	cout << "                   ***  *           *********          \n";	
	}
	cout << "                    *  *       ***  *  *  *            \n";
	cout << "                  *****           **   *   *           \n";
	cout << "                    *                  *    ***        \n";
	cout << "                   * *               **        *       \n";
	cout << "                  *   *                                \n";
	cout << "                                                       \n";
};


void playerWin(){	
	cout << "*******************************************************\n";
	for(int i = 0; i < 3; i++) cout << "*                                                     *\n";
	cout << "*                   YOU WIN!!!                        *\n";
	for(int i = 0; i < 3; i++) cout << "*                                                     *\n";
	cout << "*******************************************************\n";
};


void playerLose(){
	cout << "*******************************************************\n";
	cout << "*                                                     *\n";
	cout << "*                   YOU LOSE!!!                       *\n";
	cout << "*                                                     *\n";
	cout << "*******************************************************\n";
};


int main(){
	srand(time(0));
	Unit hero,mons;
	hero.create("Hero");
	mons.create("Monster");	
	int turn_count = 1;
	char player_action = '\0',monster_action = '\0';
	int p = 0, m = 0;
	while(true){
		mons.newTurn();	
		hero.newTurn();			
		mons.showStatus();
		drawScene(player_action,p,monster_action,m);
		hero.showStatus();		
		cout << "[A] Attack [H] Heal [G] Guard [E] Exit";
		cout << "\n[Turn " << turn_count << "] Enter your action: ";
		cin >> player_action;
		player_action = toupper(player_action);
		if(player_action == 'E') break; 
		
		int temp = rand()%3;
		if(temp <= 1) monster_action = 'A';
		else if(temp == 2) monster_action = 'G';
		
		if(player_action == 'G') hero.guard();
		if(monster_action == 'G') mons.guard();
		
		if(player_action == 'H') p = hero.heal();
		
		if(player_action == 'A') p = hero.attack(mons); 
		if(monster_action == 'A') m = mons.attack(hero); 
		
		if(hero.isDead()){
			drawScene(player_action,p,monster_action,m);
			playerLose();
			break; 
		}
		
		if(mons.isDead()){
			drawScene(player_action,p,monster_action,m);
			playerWin();
			break; 
		}
		
		turn_count++;
	}
	return 0;
}
