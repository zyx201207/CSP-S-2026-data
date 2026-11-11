#include<bits/stdc++.h>
using namespace std;
bool bd(char a){
	if(a=='F' or a=='D') return 1;
	else return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c;
	string b,d;
	cin>>a>>b>>c>>d;
	if(a==c) cout<<1;
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(b[0]==d[0] and b[1]==d[1]) cout<<1;
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if(bd(b[2]) == bd(d[2])) cout<<1;
	else{
		cout<<0<<0;
		return 0;
	}
	if(bd(b[2]) or (b[2]=='B' or d[2]=='B')) cout<<1;
	else{
		cout<<0;
		return 0;
	}
	return 0;
} 
