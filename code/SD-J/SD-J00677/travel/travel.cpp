#include <bits/stdc++.h>
#define int long long
using namespace std;
bool pd(char x,char y){
	if(x=='C'&&y=='D') return 0;
	if(x=='D'&&y=='F') return 1;
	return (x+1)==y;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int x,y;
	string s1,s2;
	cin >>x>>s1>>y>>s2;
	if(x==y){
		cout <<1;
	}else{
		cout <<"0000";
		return 0;
	}
	string p=s1.substr(0,2);
	string q=s2.substr(0,2);
	if(p==q){
		cout <<1;
	}else{
		cout <<"000";
		return 0;
	}
	if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
		cout <<1;
	}else{
		cout <<"00";
		return 0; 
	}
	char t=s1[2];
	char u=s2[2];
	if(t>u) swap(t,u);
	if(pd(t,u)){
		cout <<1;
	}else{
		cout <<0;
	}
	return 0;
} 
/*
This is my last race.
Although I am 13 years old,I am going to AFO.
My girlfriend can not code,but I love her.
My luogu name is shaomalou.
I'm from Qingdao.But I do not want to tell you which middle school I am in.
I think CCF(coin collceting) loves me very much.
But I only have 246pts.
All right. MIHUOXINGWEIDASHANG is waiting for me.
*/
