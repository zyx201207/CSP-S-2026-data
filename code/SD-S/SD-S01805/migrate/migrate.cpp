#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,maxx=-3e17,minx=3e17;
const int N=5e5+5;
vector<int> edge[N];
int cnt;
int a[N];
int vis[N];
int b[N];
int d[3005][3005];
int v[N];
int prefix[N];
int vv[3005][3005];
void dfs(int x,int fa,int u,int sum){
	int m=edge[x].size();
//	cout<<x<<" "<<fa<<" "<<sum<<endl;
	if(x!=fa&&d[x][fa]==sum&&!vv[x][u]){
		v[x]++;
		vv[x][u]=1;
		if(v[x]==2){
			cnt++;
//			cout<<"SSS"<<" "<<x<<" "<<fa<<" "<<sum<<" "<<u<<" "<<v[x]<<endl;
		}
		else if(v[x]==3){
			cnt--;
//			cout<<"la wan le"<<" "<<x<<" "<<fa<<" "<<sum<<" "<<u<<" "<<v[x]<<endl;
		}
		else{
//			cout<<"work"<<" "<<x<<" "<<fa<<" "<<sum<<" "<<u<<" "<<v[x]<<endl;
		}
	}
	for(int i=0;i<m;i++){
		int v=edge[x][i];
		if(!vis[v]){
			vis[v]=1;
			dfs(v,fa,x,sum+1);
			vis[v]=0;
		}
	} 
	return;
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;
	cin>>C>>T;
	while(T--){
		int n,x;
		scanf("%lld%lld",&n,&x);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			v[i]=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				d[i][j]=3e17;
			}
			d[i][i]=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(a[i]-a[j])<=x){
					d[i][j]=1;
					d[j][i]=1;
					edge[i].push_back(j);
					edge[j].push_back(i);
				}
			}
		}
		cnt=0;
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
				}
			}
		}
		for(int i=1;i<=n;i++){
			vis[i]=1;
			for(int j=1;j<=n;j++){
				v[j]=0;
			}
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					vv[j][k]=0;
				}
			}
//			cout<<"--------------------------"<<endl;
			dfs(i,i,i,0);
			vis[i]=0;
		}
		printf("%lld\n",cnt/2);
	}
	return 0;
}





























