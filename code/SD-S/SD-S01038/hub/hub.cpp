#include<iostream>
#include<vector>
using namespace std;
vector<int> g[5000];
int f[5000];
int a[5000];
int c[505][505];
int find(int x){
	if(f[x]!=x) f[x]=find(f[x]);
	return f[x];
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int up,t;
	cin>>up>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		if(n==k){
			cout<<0<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) c[i][j]=0x3f3f3f3f;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
			c[u][v]=1;
			c[i][i]=0;
			c[i+1][i+1]=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					c[i][j]=min(c[i][j],c[i][k]+c[k][j]);
				}
			}
		}
		int U=(1<<n),anss=0x3f3f3f3f;
		for(int i=0;i<U;i++){
			int cnt=0;
			for(int j=0;j<n;j++){
				f[i+1]=i+1;
				a[i]=0;
				if(i&(1<<j)) cnt++,a[i]=1;
			}
			if(cnt!=k) continue;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(a[i]&&a[j]&&find(i)!=find(j)){
						f[find(i)]=find(j);
					}
				}
			}
			cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i]&&f[i]==i) cnt++;
			}
			if(cnt>2) continue;
			int cntt,ans=0;
			for(int i=1;i<=n;i++){
				cntt=0x3f3f3f3f;
				for(int j=1;j<=n;j++){
					if(a[j]==1){
						cntt=min(cntt,c[i][j]);
					}
				}
				ans=max(ans,cntt);
			}
			anss=min(anss,ans);
		}
		cout<<anss<<"\n";
	}
	return 0;
}
