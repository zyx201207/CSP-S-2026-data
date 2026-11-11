#include<bits/stdc++.h>
using namespace std;
long long c,t,n,l,x[5005],d[5005],p[5005],ans;
queue<long long>q;
bitset<5005>b;
int main(){
	int i,j;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>l;
		for(i=1;i<=n;i++)cin>>x[i];
		for(i=1;i<=n;i++){
			while(!q.empty())q.pop();
			memset(d,0x3f,sizeof d);
			memset(p,0,sizeof p);
			b.reset();
			q.push(i);
			p[i]=1;
			d[i]=0;
			b[i]=1;
			while(!q.empty()){
				int u=q.front();q.pop();
				for(int v=u+1;x[v]-x[u]<=l&&v<=n;v++){
					if(d[v]>d[u]+1)d[v]=d[u]+1,p[v]=p[u];
					else if(d[v]==d[u]+1)p[v]+=p[u];
					if(b[v])continue;
					b[v]=1;
					q.push(v);
				}
			}
			for(j=1;j<=n;j++)if(p[j]==2)ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
