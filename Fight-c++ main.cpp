#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#define cls system("cls");
#define dly Sleep(1000);
using namespace std;
int rocket_m[100005],rocket_w[100005];
int number;
int n=3,m=1;
int player_number=0;
int player_y_atk,player_y_energy,player_y_mana;
string player_name="player";
int player_hp=50,player_mana=50,player_atk=2,player_energy=100,player_lv=1;
int player_exp=0;
int player_hp_max=50;
int player_mana_max=50,player_energy_max=100;
int player_gold=0;
struct node{
	string name="";
	int atk=0;
	int mana=0;
	int energy=0;
}wuqi[100005];
struct sk{
	string name="";
	int hp=0;
	int energy=0;
	int mana=0;
	int gold=0;
}yaopin[100005];
bool die(int hp){
	if(hp<=0){
		return true;
	}
	else return false;
}
void login(){
	printf("你要干什么？\n1.登录 2.注册 3.删除账号");
	while(1){
		if(_kbhit()){
			int ch=getch();
			if(ch==49){
				cls
				printf("用户名:");
				string s;
				cin>>s;
				cls
				printf("密码:");
				string h;
				cin>>h;
				for(int i=1;i<=1;i++){
					ifstream syd("loginlist");
					string a,b;
					syd>>a>>b;
					//cout<<a<<b;
					if(s==a){
						if(h==b){
							syd.close();
							printf("登陆成功！");
							dly
							cls
							return;
						}
					}
					syd.close();
				} 
				printf("登录失败");
				exit(0);
			}
			if(ch==50){
				cls
				printf("用户名:");
				string s;
				cin>>s;
				cls
				printf("密码:");
				string h;
				cin>>h;
				ofstream bjq("loginlist");
				bjq<<s<<' '<<h<<endl;
				bjq.close();
				cls
				player_number++;
				break;
			}
			if(ch==51){
				cls
				printf("已删除"); 
				system("DEL save.txt");
				system("DEL loginlist");
				dly
				cls
				exit(0); 
			} 
		}
	}
}
void fight(string boss_name,int boss_hp,int boss_atk,int exp,int wu=0){
	cls
	while(true){
		cout<<boss_name;
		printf(": HP:%d\n",boss_hp);
		cout<<player_name;
		printf(": HP:%d/%d 法力：%d/%d 体力:%d/%d",player_hp,player_hp_max,player_mana,player_mana_max,player_energy,player_energy_max);
		printf("\n\n你要做什么\n1.攻击 2.逃跑");
		while(1){
			if(_kbhit()){
				int ch=getch();
				if(ch==49){
					cls
					if(player_energy<=(player_atk/5)+10+player_y_energy){
						printf("你的体力不够！");
						dly
						cls
						break;
					}
					printf("你对Boss造成了%d点伤害，",player_atk+player_y_atk);
					printf("你消耗了%d点体力\n",(player_atk/5)+10+player_y_energy);
					player_energy-=(player_atk/5)+10+player_y_energy;
					dly
					printf("Boss对你造成了%d点伤害。",boss_atk);
					boss_hp-=player_atk+player_y_atk;
					player_hp-=boss_atk; 
					dly
					cls
					if(die(player_hp)){
						system("color 40");
						printf("你  死  了");
						dly
						cls
						exit(0);
					}
					if(die(boss_hp)){
						printf("你胜利了");
						player_exp+=exp;
						dly
						if(wu!=0){
							printf("你获得了");
							cout<<yaopin[wu].name;
							dly
							number++;
							rocket_m[number]=wu;
						}
						cls
						return; 
					}
					break;
				}
				if(ch==50){
					cls
					printf("你逃跑了"); 
					return;
				}
			}
		}
	}
}
void start(){
	ifstream zyc("save.txt");
	zyc>>player_name>>player_hp>>player_mana>>player_atk>>player_energy>>player_lv>>player_exp>>player_hp_max>>player_mana_max>>player_energy_max;
	zyc>>player_y_atk>>player_y_energy>>player_y_mana>>number>>player_gold;
	for(int i=1;i<=number;i++){
		zyc>>rocket_m[i];
	}
	zyc.close();
	printf("要做什么?\n1.开始游戏 2.退出");
	while(1){
		if(_kbhit()){
			int ch=getch();
			if(ch==49){
				cls
				return;
			}
			if(ch==50){
				exit(0);
			}
		} 
	} 
}
void sb(){
	cls
	printf("选择一个打吧\n1.小怪\n2.大怪\n3.syd\n4.体力瓶怪\n5.【数据缺失】\n6.刷经验怪\n7.杰哥");
	while(1){
		if(_kbhit){
			int ch=getch();
			if(ch==49){
				fight("小怪",20,10,20);
				break;
			}
			if(ch==50){
				fight("大怪",40,20,50);
				break;
			}
			if(ch==51){
				fight("syd",1,10,5,1);
				break;
			}
			if(ch==52){
				if(player_mana<=(player_lv/5)+50){
					printf("你的法力不够！");
					dly
					cls
					break;
				}
				else{
					player_mana-=(player_lv/5)+50;
					fight("体力瓶怪",50,20,10,2);
					player_energy+=90;
					if(player_energy>player_energy_max){
						player_energy=player_energy_max;
					}
					cls
					break;
				}
			}
			if(ch==53){
				fight("【数据缺失】",1000,10,500);
				return;
			} 
			if(ch==54){
				fight("刷经验怪",10,5,10); 
			} 
			if(ch==55){
				fight("杰哥",50,5,100,3);
			} 
		}
	}
}
void choose_5(){
	cls
	if(player_y_atk!=0){
		printf("你没有卸下武器！");
		return;
	}
	for(int i=1;i<=n;i++){
		printf("%d.",i);
		cout<<wuqi[i].name;
		cout<<endl;
	}
	while(1){
		if(_kbhit()){
			int ch=getch();
			if(ch==49){
				if(player_energy<50){
					cls
					printf("你没有足够的体力以拿起它！"); 
					dly
					cls
					return;
				}
				else{
					cls
					printf("已装备");
					dly
					cls 
					player_y_atk+=wuqi[1].atk;
					player_y_energy+=wuqi[1].energy;
					return;
				}
			}
			if(ch==50){
				if(player_energy<1000){
					cls
					printf("你没有足够的体力以拿起它！"); 
					dly
					cls
					return;
				}
				else{
					cls
					printf("已装备");
					dly
					cls 
					player_y_atk+=wuqi[2].atk;
					player_y_energy+=wuqi[2].energy;
					return;
				}
			}
			if(ch==51){
				if(player_energy<300){
					cls
					printf("你没有足够的体力以拿起它！"); 
					dly
					cls
					return;
				}
				else{
					cls
					printf("已装备");
					dly
					cls 
					player_y_atk+=wuqi[3].atk;
					player_y_energy+=wuqi[3].energy;
					return;
				}
			} 
		}
	}
}
void maichu(){
	cls
	printf("你要卖出什么?\n");
	if(number==0){
		cls
		printf("背包里空空如也");
		dly
		cls
		return;
	}
	for(int i=1;i<=number;i++){
		if(rocket_m[i]!=0)cout<<i<<'.'<<yaopin[rocket_m[i]].name<<endl;
	}
	printf("Input>>>");
	int kkk;
	cin>>kkk;
	printf("已卖出");
	player_gold+=yaopin[rocket_m[kkk]].gold;
	rocket_m[kkk]=0;
	dly
	cls
	return;
}
bool gold(int gold_down){
	if(player_gold<gold_down){
		return false;
	}
	else{
		return true;
	}
}
void shop(){
	printf("要买什么？\n1.syd的结晶 15gold\n2.杰哥的dua郎秘籍 30gold");
	while(1){
		if(_kbhit()){
			int ch=getch();
			if(ch==49){
				if(gold(15)){
					player_gold-=15;
					printf("已买入");
					number++;
					rocket_m[number]=1;
					dly 
					return;
				}
				else{
					printf("你的金钱不够！");
					dly
					return;
				}
			}
			if(ch==50){
				if(gold(30)){
					player_gold-=30;
					printf("已买入");
					number++;
					rocket_m[number]=3;
					dly 
					return;
				}
				else{
					printf("你的金钱不够！");
					dly
					return;
				}
			}
		}
	}
}
void energy(){
	if(player_energy>player_energy_max){
		printf("你的体力溢出了");
		player_energy=player_energy_max;
		return;
	}
	else{
		return;
	}
}
void mana(){
	if(player_mana>player_mana_max){
		printf("你的法力溢出了");
		player_mana=player_mana_max;
		return;
	}
	else{
		return;
	}
}
void hp(){
	if(player_hp>player_hp_max){
		printf("你的hp溢出了");
		player_hp=player_hp_max;
		return;
	}
	else{
		return;
	}
}
void use(){
	cls
	printf("你要使用什么?\n");
	if(number==0){
		cls
		printf("背包里空空如也");
		dly
		cls
		return;
	}
	for(int i=1;i<=number;i++){
		if(rocket_m[i]!=0)cout<<i<<'.'<<yaopin[rocket_m[i]].name<<endl;
	}
	printf("Input>>>");
	int kkksc003; 
	cin>>kkksc003;
	printf("已使用");
	player_energy+=yaopin[rocket_m[kkksc003]].energy;
	player_mana+=yaopin[rocket_m[kkksc003]].mana;
	player_hp+=yaopin[rocket_m[kkksc003]].hp;
	energy();
	mana(); 
	hp();
	rocket_m[kkksc003]=0;
	dly
	cls
	return;
}
void body(){
	if(player_exp>=player_lv*30){
		player_exp-=player_lv*30;
		player_lv++;
		printf("你升级了！");
		player_atk+=1;
		player_hp_max+=20;
		player_mana_max+=10;
		player_energy_max+=40;
		player_hp=player_hp_max;
		player_mana=player_mana_max;
		player_energy=player_energy_max;
		dly
		cls
	}
	cls
	printf("要做什么？\n1.打怪 2.查看 3.存档 4.退出 5.选择武器 6.卸下武器 7.回血 8.查看背包 9.商场 0.使用物品");
	while(1){
		if(_kbhit()){
			int ch=getch();
			if(ch==49){
				sb();
				break;
			}
			if(ch==50){
				cls
				cout<<player_name;
				printf(":\nHP:%d/%d\nATK:%d\n法力:%d/%d\n体力:%d/%d\nLv.%d\nexp:%d/%d\ngold:%d",player_hp,player_hp_max,player_atk,player_mana,player_mana_max,player_energy,player_energy_max,player_lv,player_exp,player_lv*50,player_gold);
				dly
				dly
				dly
				dly
				dly
				cls
				break;
			}
			if(ch==51){
				cls
				printf("已存档");
				ofstream wjt("save.txt");
				wjt<<player_name<<' '<<player_hp<<' '<<player_mana<<' '<<player_atk<<' '<<player_energy<<' '<<player_lv;
				wjt<<' '<<player_exp<<' '<<player_hp_max<<' '<<player_mana_max<<' '<<player_energy_max;
				wjt<<' '<<player_y_atk<<' '<<player_y_energy<<' '<<player_y_mana<<' '<<number<<' '<<player_gold;
				for(int i=1;i<=number;i++){
					wjt<<' '<<rocket_m[i];
				}
				wjt.close();
				dly
				cls
				break;
			}
			if(ch==52){
				exit(0);
			}
			if(ch==53){
				choose_5();
				dly
				break;
			}
			if(ch==54){
				cls
				if(player_y_atk==0){
					printf("你没有装备武器");
					dly
					cls
					break;
				}
				player_y_atk=player_y_energy=player_y_mana=0;
				printf("已卸下");
				dly
				cls
				break;
			} 
			if(ch==55){
				cls
				printf("你要回多少血？");
				int hp_add;
				cin>>hp_add;
				if(player_mana<=player_lv*hp_add){
					printf("你的法力不够！"); 
					dly
					cls
					break;
				} 
				else{
					cls
					printf("你耗费了%d点法力，回了%d点HP",player_lv*hp_add,hp_add);
					dly
					player_mana-=player_lv*hp_add;
					player_hp+=hp_add;
					if(player_hp>player_hp_max){
						cls
						printf("你的HP溢出了");
						dly
						player_hp=player_hp_max;
					}
					cls;
					break;
				}
			}
			if(ch==56){
				cls 
				if(number==0){
					cls
					printf("背包里空空如也");
					dly
					cls
					break;
				}
				for(int i=1;i<=number;i++){
					if(rocket_m[i]!=0)cout<<i<<'.'<<yaopin[rocket_m[i]].name<<endl;
				}
				printf("按0可以退出 按1卖出");
				while(1){
					if(kbhit()){
						int ch=getch();
						if(ch==48){
							return;
						}
						if(ch==49){
							maichu();
							dly
							return;
						} 
					}
				}
			} 
			if(ch==57){
				shop();
			}
			if(ch==48){
				use();
			} 
			break;
			 
		} 
	} 
}
void dingyi(){
	yaopin[0].name="卖出品的痕迹"; 
	yaopin[1].name="syd的结晶";
	yaopin[1].gold=10;
	yaopin[1].energy=10;
	yaopin[1].hp=5;
	wuqi[1].atk=3;
	wuqi[1].name="小木棍"; 
	wuqi[1].energy=5;
	wuqi[2].atk=100;
	wuqi[2].name="屠龙大宝刀";
	wuqi[2].energy=200;
	wuqi[3].atk=20;
	wuqi[3].name="Killer's 【数据缺失】";
	wuqi[3].energy=50;
	yaopin[2].name="空玻璃瓶"; 
	yaopin[2].gold=3;
	yaopin[3].name="杰哥的dua郎秘籍" ;
	yaopin[3].gold=20; 
	yaopin[3].mana=100;
	yaopin[3].hp=10;
}
int main(){
	system("title Fight");
	system("color 0");
	login();
	dingyi();
	start();
	printf("需要改名吗？\n1.要 2.不\n当前玩家名：");
	cout<<player_name; 
	while(1){
		if(_kbhit){
			int ch=getch();
			if(ch==49){
				printf("\n请输入你的名字\nInput>>>"); 
				cin>>player_name;
				system("color 0");
				break;
				
			}
			if(ch==50){
				break;
			}
		}
	}
	cls 
	while(1){
		body();
	}
}
