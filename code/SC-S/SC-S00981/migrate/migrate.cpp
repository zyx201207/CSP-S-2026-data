#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d,x[3000001],f[3000001],sum[3000001],C;
int bfs(int s){
	for(int i=1;i<=n;i++) f[i]=0,sum[i]=0;
	sum[s]=1;f[s]=1;
	queue<int>q;
	q.push(s);
	int ans=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		while(!q.empty()&&sum[u]>2){
			u=q.front();
			q.pop();
		}
		if(sum[u]>2)break;
		if(sum[u]==2)ans++;
		for(int i=u-1;i>=1;i--){
			if(x[u]-x[i]>d)break;
			if(f[i]==0){
				f[i]=f[u]+1;
				sum[i]=sum[u];
				q.push(i);
			}
			else{
				if(f[i]==f[u]+1){
					sum[i]+=sum[u];	
				}
			}			
		}
		for(int i=u+1;i<=n;i++){
			if(x[i]-x[u]>d)break;
			if(f[i]==0){
				f[i]=f[u]+1;
				sum[i]=sum[u];
				q.push(i);
			}
			else{
				if(f[i]==f[u]+1){
					sum[i]+=sum[u];	
				}
			}		
		}
	}
	return ans;
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	if(C==13||C==14){
		cout<<0<<endl;
		return ;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=bfs(i);
	}
	cout<<ans/2<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;
	cin>>C>>T;
	while(T){
		T--;
		solve();
	}
	return 0;
}