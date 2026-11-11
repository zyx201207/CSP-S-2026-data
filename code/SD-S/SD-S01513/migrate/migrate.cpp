#include<bits/stdc++.h>
#define int long long 
using namespace std;
int x[2000010];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	int c,t;
	while(t--){
		int n,d;
		cin>>n>>d;
		memset(x,0,sizeof x);
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}int c=x[n]-x[n-1],f=0;
		for(int i=2;i<=n;i++){
			if(x[i]-x[i-1]!=c){
				f=1;
				break;
			}
		}if(f==0&&d%c==0){
			cout<<0<<"\n";
		}int x1=x[n/2+n%2];
		if(x1-d<=x[1]&&x1+d>=x[n]){
			cout<<0<<"\n";
		}
	}
	return 0;
}
