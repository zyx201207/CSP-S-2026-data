#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b,c,d,e,f;
char x,y;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>x>>c>>d>>y;
	if(x=='A'||x=='B'||x=='C')e=1;
	else e=0;
	if(y=='A'||y=='B'||y=='C')f=1;
	else f=0;
	if(a==c){
		cout<<"1";
		if(b==d){
			cout<<"1";
			if(e==f){
				cout<<"1";
				if(abs(x-y)==1)cout<<"1";
				else cout<<"0";
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	
	return 0;
}
