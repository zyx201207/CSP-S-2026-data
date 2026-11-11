#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,u,v,b[2000005],k2=LLONG_MAX,d[105][105];
vector<long long> a[2000005];
void aa(long long o,long long p){
	if(o==k){
		long long ans=1;
		for(int i=1;i<=n;i++){
			if(b[i]){
				for(int j=1;j<=n;j++){
					if(b[j]){
						if(i!=j){
							ans=max(d[i][j],ans);
						}
					}
				}
			}
		}
		k2=min(k2,ans);
	}
	for(int i=p;i<=n;i++){
		b[i]=1;
		aa(o+1,i+1);
		b[i]=0;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				d[u][v]=LLONG_MAX;
			}
		}
		for(int i=1;i<n;i++){
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
			d[u][v]=1;
		}
		for(int i=1;i<=n;i++){
			for(int k3=1;k3<=n;k3++){
				if(i==k3){
					continue;
				}
				for(int j=1;j<=n;j++){
					if(j==k3){
						continue;
					}
					d[i][j]=min(d[i][j],d[i][k3]+d[k3][j]);
				}
			}
		}
		aa(0,1);
		cout<<k2<<'\n';
	}
}
