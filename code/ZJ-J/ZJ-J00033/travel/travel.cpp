#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string a,c,b,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		string x,y;
		for(ll i=0;i<=1;i++){
			x+=b[i];
			y+=d[i];
		}
		if(x==y){
			cout<<1;
			if((b[2]<='C'&&d[2]>='D')||(b[2]>='D'&&d[2]<='C')){
				cout<<"00";
			}else{
				cout<<1;
				if(abs(b[2]-d[2])==1||(b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')){
					cout<<1;
				}else{
					cout<<0;
				}
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
//01 05F 01 05D