#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool tongyice(char a,char b){
	if(a>b) swap(a,b);
	if(a=='D'&&b=='F') return true;
	if(a=='A'&&b=='B') return true;
	if(a=='A'&&b=='C') return true;
	if(a=='B'&&b=='C') return true;
	return false;
}
bool xianglin(char a,char b){
	if(a>b) swap(a,b);
	if(a=='D'&&b=='F') return true;
	if(a=='A'&&b=='B') return true;
	if(a=='B'&&b=='C') return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int p1=(s1[0]-'0')*10+(s1[1]-'0');
	int p2=(s2[0]-'0')*10+(s2[1]-'0');
	char w1=s1[2];
	char w2=s2[2];
	if(c1==c2) cout<<1;
	else cout<<0;
	if(c1==c2&&p1==p2) cout<<1;
	else cout<<0;
	if(c1==c2&&p1==p2&&tongyice(w1,w2)) cout<<1;
	else cout<<0;
	if(c1==c2&&p1==p2&&tongyice(w1,w2)&&xianglin(w1,w2))
		cout<<1;
	else cout<<0;
	return 0;
}

