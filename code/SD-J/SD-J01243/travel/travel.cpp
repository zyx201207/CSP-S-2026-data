#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a,b;
string x,y;
bool ck(){
	if(x[2]>'C'&&y[2]>'C') return 1;
	if(x[2]=='B'||y[2]=='B') return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>a>>x>>b>>y;
	if(a==b){
		cout<<"1";
		ll o=(x[0]-'0')*10+x[1]-'0';
		ll p=(y[0]-'0')*10+y[1]-'0';
		if(o==p){
			cout<<"1";
			if(x[2]<='C'&&y[2]<='C'||x[2]>'C'&&y[2]>'C'){
				cout<<"1";
				if(ck()) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} 
