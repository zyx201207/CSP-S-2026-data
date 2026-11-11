#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+7;
const int M=1e7+7;
const int inf=0x3f3f3f3f3f3f3f3f;
int C,D;
int n,m,q;
int W[N];
int mp[501][501];
struct Node{
	int d;
	int da[21];
	int dt[21];
}a[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>D>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j) mp[i][j]=inf;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>W[i];
	}
	for(int i=1;i<=n;i++){
		int k,x,t;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>t;
			a[x].d++;
			a[x].da[a[x].d]=i;
			a[x].dt[a[x].d]=t;
		}
	}
	for(int i=1;i<=m;i++){
//		for(int j=2;j<=a[i].d;j++){
//			mp[a[i].da[1]][a[i].da[j]]=min(mp[a[i].da[1]][a[i].da[j]],a[i].dt[1]+a[i].dt[j]);
//		}
		for(int j=1;j<=a[i].d;j++){
			for(int k=j+1;k<=a[i].d;k++){
				mp[a[i].da[k]][a[i].da[j]]=mp[a[i].da[j]][a[i].da[k]]=min(mp[a[i].da[j]][a[i].da[k]],a[i].dt[k]+a[i].dt[j]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
			}
		}
	}
	while(q--){
		int x,y,ans=inf;
		cin>>x>>y;
		for(int i=1;i<=a[x].d;i++){
			for(int j=1;j<=a[y].d;j++){
				ans=min(ans,W[x]+W[y]+a[x].dt[i]+a[y].dt[j]+mp[a[x].da[i]][a[y].da[j]]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}