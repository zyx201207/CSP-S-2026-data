#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,inf=0x3f3f3f3f;
int C,T;
int n,k,ans;
int d[N],a[N][N];
int f[N];
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy) return;
	f[fx]=fy;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
		ans=inf;
		int x,y;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				a[i][j]=inf;
		for(int i=1;i<n;i++){
			cin>>x>>y;
			a[x][y]=a[y][x]=1;
		}
		for(int j=0;j<(1<<n);j++){
			int cnt=0;
			for(int i=1;i<=n;i++){
				f[i]=i;
				a[i][i]=0;
				if((j>>i-1)&1) cnt++;
			}
			if(cnt!=k) continue;
			for(int i=1;i<=n;i++)
				for(int v=1;v<=n;v++)
					if(a[i][v]&&((j>>i-1)&1)&&((j>>v-1)&1))
						merge(i,v);
			cnt=0;
			for(int i=1;i<=n;i++)
				if(f[i]==i) cnt++;
			if(cnt>2) continue;
			for(int k=1;k<=n;k++)
				for(int u=1;u<=n;u++)
					for(int v=1;v<=n;v++)
						if(a[u][k]!=inf&&a[k][v]!=inf)
							a[u][v]=min(a[u][v],a[u][k]+a[k][v]);
			int res=0;
			for(int i=1;i<=n;i++){
				d[i]=inf;
				for(int k=1;k<=n;k++)
					if((j>>k-1)&1) d[i]=min(d[i],a[i][k]);
				res=max(res,d[i]);
			}
			ans=min(ans,res);
		}
		cout<<ans;
	}
	return 0;
}
