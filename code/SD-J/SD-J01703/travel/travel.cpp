#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,p1,p2;
char h1,h2;
bool check (char x,char y){
	if (x=='A' && y=='B') return true;
	if (y=='A' && x=='B') return true;
	if (x=='B' && y=='C') return true;
	if (x=='C' && y=='B') return true;
	if (x=='D' && y=='F') return true;
	if (x=='F' && y=='D') return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c1>>c2>>s1>>s2;
	p1+=c2[0];
	p1+=c2[1];
	h1=c2[2];
	p2+=s2[0];
	p2+=s2[1];
	h2=s2[2];
//	cout<<p1<<" "<<p2<<' '<<h1<<" "<<h2<<endl;
	if (c1!=s1){
		cout<<"0000";
		return 0;
	}
	else if(p1!=p2){
		cout<<"1000";
		return 0;
	}
	else if(((h1=='A' || h1=='B' || h1=='C') && (h2=='A' || h2=='B' || h2=='C')) || ((h1=='D' || h1=='F') && (h2=='D' || h2=='F'))){
		if (check(h1,h2)){
			cout<<"1111";
		}
		else {
			cout<<"1110";
		}
	}
	else {
		cout<<"1100";
		return 0;
	}
	return 0;
}
