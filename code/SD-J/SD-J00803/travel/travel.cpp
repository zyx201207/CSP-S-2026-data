#include<iostream>
#include<algorithm>
#include<vector>
#define int long long
using namespace std;
string s1,c1,s2,c2;
int char_to_int(char c){
	if(c<'F') return c-'A'+1;
	return 5;
}
signed main(){
	//bie gua fen bie gua fen xi xi ai fu wo qiu ni le
	
	//Trick||Treat!
	//freopen("travel.in","r",stdin); 
	//freopen("recall.in","r",stdin);
	//freopen("recall.out","w",stdout);
	//never gonna give you up, never gonna let you down~
	//9:44 AK. good. easy easy.
	//It might will be (or"It will might be"?) the only one contest AKed by me,
	//but it is also possible that i will grow after this season(?
	//who knows.
	//too many grammer mistakes, i think.
	//o that's not important.
	//i think i should jian cha yi xia now.
	//long long, MLE, RE, file names.
	//10:06. bye.
	//10:15
	//I'm back.
	//red orange orange green I guess?
	//too easy. xi xi ai fu you should give children some challenges!
	//I'm so vegetable that I need half an hour to solve T4!
	//Anyway
	//CSP-S & NOIP 2026 RP++!
	//maybe somebody will read these words after a month?
	//so guanzhu luogu Phi_Mobius DUODUOTU somebody666 super_wyh thanks meow!
	//look at the bottom of the code.
	
	//RP++;RP++;RP++;    RP++;RP++;RP++;
	//RP++;RP++;RP++;    RP++;RP++;RP++;
	//RP++;      RP++;   RP++;      RP++;
	//RP++;       RP++;  RP++;      RP++;        RP++;             RP++;
	//RP++;      RP++;   RP++;      RP++;        RP++;             RP++;
	//RP++;RP++;RP++;    RP++;RP++;RP++;    RP++;RP++;RP++;   RP++;RP++;RP++;
	//RP++;   RP++;      RP++;              RP++;RP++;RP++;   RP++;RP++;RP++;
	//RP++;    RP++;     RP++;                   RP++;             RP++;
	//RP++;     RP++;    RP++;                   RP++;             RP++;
	//RP++;      RP++;   RP++;
	//RP++;       RP++;  RP++;
	//RP++;        RP++; RP++;
	
	//write to myself in the afternoon:
	//dont be nervous. calm down. you can win. you will win.
	//think twice, code once. 
	//bu yao yi shi liu zuo ti.
	//Thick Twice, Code Once.
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>c1>>s2>>c2;
	if(s1==s2){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(c1[0]==c2[0] && c1[1]==c2[1]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	int x1=char_to_int(c1[2]);
	int x2=char_to_int(c2[2]);
	if(!((x1>3)^(x2>3))){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(x1<x2) swap(x1,x2);
	if(x2+1==x1){
		cout<<1;
	}
	else{
		cout<<"0";
		return 0;
	}
	return 0;
}

//tong tong
//DOUDOU

//shen ming shen ming zhang kai zui
//rang wo zhi dao wo shi shei
//ta ba wo xiang tian shang tui
//lue guo chen yu hui
//bu de bu ting xie bu ting xie
//hei ye zai bei shang fei
//lai kuang huan ba kuang huan ba
//yong yuan bu xia zhui

//tai yang tai yang qing ni gao su wo
//wei shen me wei shen me
//yi han na me duo
//ye mu ye mu qing ni gao su wo
//gai zen me zuo zen me zuo
//ling hun cai bu hui po

//tong yi sheng luo xia
//guo shi tong yi sheng luo xia
//suo suo suo suo suo suo suo 
//wo de jiao xia kai le hua
//tong yi sheng luo xia
//gu tou tong yi sheng luo xia
//ke yi la ke yi la ke yi bian hui hai zi la

//shen ming shen ming zhang kai zui
//rang wo zhi dao wo shi shei
//ta ba wo xiang tian shang tui
//lue guo chen yu hui
//bu de bu ting xie bu ting xie
//hei ye zai bei shang fei
//lai kuang huan ba kuang huan ba
//yong yuan bu xia zhui

//qing shen ming shen ming zhang kai zui
//rang wo zhi dao wo shi shei
//ta ba wo xiang tian shang tui
//lue guo chen yu hui
//bu de bu ting xie bu ting xie
//hei ye zai bei shang fei
//jiu an xin ba an xin ba
//yong yuan bu xia zhui

//qing shen ming shen ming zhang kai zui
//rang wo zhi dao wo shi shei
//ta ba wo xiang tian shang tui
//lue guo chen yu hui
//bu de bu ting xie bu ting xie
//hei ye zai bei shang fei
//lai kuang huan ba kuang huan ba
//yong yuan bu xia zhui

//wu... fei guo mai sui
//wu... fei guo mi hong guang hui
//wu... fei guo mu bei
//wu... fei guo wa li dui

//wu... fei guo mai sui
//wu... fei guo mi hong guang hui
//wu... fei guo mu bei
//wu... fei guo wa li dui

//zhui yi(recall)
//you yu ping ce ji xing neng cha yi, ben ti shi xian zeng jia zhi 2s(or 4s?)
//wo chang chang zhui yi guo qu.
//hui yi ding ge zai nao hai,...quan qu,zhe die,rou nian cheng tian shang duo duo bai yun.
//yun duo zhi jian yi you cha bie, ji yun hou zhong,er juan yun piao miao...
//fan huang de zhi ye li,...tai guo mo hu you zhui ru xu wu,
//guo fen qing chu you wu fa yu yue zi ji de huan xiang...
//...zhui yi yi cheng guo qu,wo dai zhe hui yi xiang qian,
//...gei wo de zhui yi zhi lv dai lai xie xu tiao zhan.
//mei hao de shi guang ceng liu guo wo de shen ti, wo bian xin man yi zu...
//wo gai zai na li ting liu? wo wen wo zi ji.
