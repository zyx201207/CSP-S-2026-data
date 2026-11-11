#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10,inf=2e18;
int C,T;
int n,d,ans;
int a[N];
int f[N],g[N],sum[N];
queue<int> q;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			f[i]=0;
			g[i]=1;
			sum[0]=1;
			q.push(i);
			for(int j=i+1;j<=n;j++){
				while(!q.empty()&&a[j]-a[q.front()]>d){
					sum[f[q.front()]]-=g[q.front()];
					q.pop();
				}
				if(q.empty()) break;
				f[j]=f[q.front()]+1;
				g[j]=sum[f[q.front()]];
				if(g[j]==2) ans++;
				sum[f[j]]+=g[j];
				q.push(j);
			}
			while(!q.empty()){
				sum[f[q.front()]]-=g[q.front()];
				q.pop();
			}
			for(int j=i+1;j<=n;j++) f[j]=0;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
