#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
int a,b;
string x,y;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>a>>x>>b>>y;
	if(a!=b){
		cout<<"0000";
	}
	else if(x[0]!=y[0]||x[1]!=y[1]){
		cout<<"1000";
	}
	else{
		int q,w;
		if(x[2]<='C'&&x[2]>='A'){
			q=0;
		}
		if(x[2]<='F'&&x[2]>='D'){
			q=1;
		}
		if(y[2]<='C'&&y[2]>='A'){
			w=0;
		}
		if(y[2]<='F'&&y[2]>='D'){
			w=1;
		}
		if(q!=w){
			cout<<"1100";
		}
		else{
			int a1=x[2]-'0',b1=y[2]-'0';
			if(abs(a1-b1)==1){
				cout<<"1111";
			}
			else{
				cout<<"1110";
			}
		}
	}
	return 0;
}
