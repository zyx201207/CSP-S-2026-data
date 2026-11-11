#include<bits/stdc++.h>
#define ll long long
using namespace std;
string c1,s1,c2,s2;
int main(){
	//100pts
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	string id1=s1.substr(0,2);
	string id2=s2.substr(0,2);
	if(id1==id2) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	int uid1=s1[2]-'A',uid2=s2[2]-'A';
	if(uid1>uid2) swap(uid1,uid2);
	if((uid1==0&&uid2==1)||(uid1==1&&uid2==2)||(uid1==3&&uid2==5)) cout<<"11";
	else if(uid1==0&&uid2==2) cout<<"10";
	else cout<<"00";
	return 0;
}
//不需要开ll，已去掉freopen的注释 
//样例全过，大样例没用啊 
//差点挂了，错了两点啊，啧题目还是要注意看好且代码不要写错啊qwq 
//9:00结，有点慢 
