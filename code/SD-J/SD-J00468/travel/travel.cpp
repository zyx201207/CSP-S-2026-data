#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
string x,y,l,r;
int a=1,b=1,c=1,d=1;
void solve(){
	cin>>x>>y>>l>>r;
	for(int i=0;i<x.size();i++){
		if(x[i]!=l[i]){
			a=0;
			break;
		}
	}
	if(a==1){
		for(int i=0;i<y.size()-1;i++){
			if(y[i]!=r[i]){
				b=0;
				break;
			}
		}
		if(b==1){
			if((y[2]<='C'&&r[2]<='C')||(y[2]>'C'&&r[2]>'C'))
				c=1;
			else c=0;
			if(c==1){
				if(abs(y[2]-r[2])==1)d=1;
				else d=0;
			}
			else d=0;
		}
		else c=0,d=0;
	}
	else b=0,c=0,d=0;
	cout<<a<<b<<c<<d;
} 
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int te=1;
//	cin>>te;
	while(te--){
		solve();
	}
	return 0;
}
