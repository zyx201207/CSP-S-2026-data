#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,f[2000010],fa[2000010];
ll d,x[2000010],ans;
vector<int>g[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c,_;cin>>c>>_;
	while(_--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i],g[i].clear();
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(x[j]-x[i]<=d)g[i].push_back(j);
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++)f[j]=0x3f3f3f3f;
			f[i]=0;fa[i]=1;
			queue<int>q;q.push(i);
			while(q.size()){
				int x=q.front();q.pop();
				if(fa[x]==2)ans++;
				for(auto &y : g[x]){
					if(f[y]>f[x]+1){
						f[y]=f[x]+1;
						fa[y]=fa[x];
						q.push(y);
					}else if(f[y]==f[x]+1)fa[y]+=fa[x],fa[y]=min(fa[y],10);
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
11 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/
