#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500001],x[501],a[501][50001],t[501][50001],u[501],ans=1e9;
void dfs(long long a1,long long a2,long long sum){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=x[i];j++){
			if(a[i][j]==a1&&u[i]==0){
				for(int k=1;k<=x[i];k++){
					if(k!=j){
						if(a[i][k]==a2)ans=min(ans,sum+t[i][j]+t[i][k]);
						u[i]+=1;
						dfs(a[i][k],a2,sum+t[i][j]+t[i][k]);
						u[i]-=1;
					}
				}
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>x[i];
		for(int j=1;j<=x[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		long long a1,a2;
		cin>>a1>>a2;
		ans=1e9;
		dfs(a1,a2,w[a1]+w[a2]);
		for(int i=1;i<=n;i++)u[i]=0;
		cout<<ans<<endl;
	}
	return 0;
}
