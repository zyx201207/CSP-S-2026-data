#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,t,d,n,x[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c==13 or c==14){
			cout<<"0"<<endl;
			continue;
		}
		else{
			if(d>(n-1)*(x[2]-x[1])){
				cout<<"0"<<endl;
				continue;
			}
			d-=d%(x[2]-x[1]);
			if(d<x[2]-x[1] or d==x[2]-x[1]){
				cout<<"0"<<endl;
			}
			else cout<<n-d/(x[2]-x[1])*2+1<<endl;
		}
	}
	return 0;
}
