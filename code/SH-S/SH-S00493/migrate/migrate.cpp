#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5,M=505;
int x[20],c[30][20],n,d;
void dfs(int now,int f){
	c[now][f]++;
//	cout<<c[now][f]<<' ';
	for(int i=now+1;i<=n;i++){
		if(x[i]-x[now]<=d)dfs(i,f+1);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int cc,t;
	cin>>cc>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++){
			memset(c,0,sizeof c);
			dfs(i,0);
			bool f=0;
			for(int j=i;j<=n;j++){
			for(int k=1;k<=8;k++){
				if(c[j][k])f=1;
				if(c[j][k]==2){
					ans++;
				}
			}
			if(f){
				break;
			}
		}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
