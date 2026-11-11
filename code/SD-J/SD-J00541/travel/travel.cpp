#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
const int M=1e6+5;
const int mod=1e9+7;
char n[5],m[5];
string a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>n>>b>>m;
	if(a==b){
		cout<<"1";
		if(n[0]==m[0]&&n[1]==m[1]){
			cout<<"1";
			if((n[2]+m[2]<134)||(n[2]+m[2]>136)){//
				cout<<"1";
				if(n<m)swap(n,m);
				if((n[2]=='C'&&m[2]=='B')||(n[2]=='B'&&m[2]=='A')||(n[2]=='F'&&m[2]=='D')||(n[2]=='B'&&m[2]=='C')||(n[2]=='A'&&m[2]=='B')||(n[2]=='D'&&m[2]=='F'))
					cout<<"1";
				else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}

