#include<bits/stdc++.h>
using namespace std;
long long a,b,x,y;
char cc,ccc;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>x>>cc>>b>>y>>ccc;
//	cout<<a<<' '<<x<<cc<<' '<<b<<' '<<y<<ccc<<'\n';
	if(cc>ccc) swap(cc,ccc); 
	if(a==b){
		cout<<1;
		if(x==y){
			cout<<1;
			if((cc=='A'&&ccc=='B') || (cc=='A'&&ccc=='C') ||(cc=='B'&&ccc=='C') || (cc=='D'&&ccc=='F')){
				cout<<1;
				if((cc=='A'&&ccc=='B') || (cc=='B'&&ccc=='C') || (cc=='D'&&ccc=='F')) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
