#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,d,a[2000055],inq[2000055],dis[2000055],vis[2000055],vised[2000055];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];inq[i]=0;dis[i]=0;vis[i]=0;vised[i]=0;
		} 
		int ans=0;
		for(int i=1;i<=n;i++){
			if(!vised[i]){
				queue<int> q;
				q.push(i);
				inq[i]=1;
				int res=0,res2=0,flag=0,f=0,t=0;
				while(!q.empty()){
					int u=q.front();
					q.pop();
					inq[u]=0;
					vised[u]=1;
					if(a[u+1]-a[u]<=d&&a[u+2]-a[u]>d&&flag>0&&u+2<=n){
						ans+=flag*(++res);
						t=res;res=1;
					}
					else if(a[u+1]-a[u]<=d&&a[u+2]-a[u]>d&&u+2<=n) res++;
					for(int i=u+1;i<=n;i++){
						if(a[i]-a[u]>d) break;
						if(!inq[i]){
							q.push(i);
							inq[i]=1;
							dis[i]=dis[u]+1;
						}
						if(vis[i]==0&&dis[i]==dis[u]+1&&i!=u+1&&dis[i]!=1){
							ans++;vis[i]=1;res2++;f++;flag++;
						}else if(vis[i]==1&&dis[i]==dis[u]+1&&i!=u+1&&dis[i]!=1){
							ans--;vis[i]=2;res2--;flag=(f==1)?-1e9:flag;
							if(f!=1) ans+=t;
							f=0;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}