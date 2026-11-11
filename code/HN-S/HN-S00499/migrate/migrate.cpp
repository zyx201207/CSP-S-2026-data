#include<bits/stdc++.h>
using namespace std;
int c,t,n,ans,num;
long long d,a[2000005],b[1000000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		for(int u=1;u<=n;u++){
			b[u]=1;
			b[u+1]=2;
			for(int v=u+2;v<=n;v++){
				b[v]=b[v-2]*2+b[v-1];
				ans+=b[v];
			}
		}
		cout<<ans;
	}
	return 0;
}
