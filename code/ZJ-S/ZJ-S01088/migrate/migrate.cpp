#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,T,n,d,i,j,fx,sx,cnt;
int x[2100000],dis[5100],dic[5100],dik[5100],vis[5100];
vector<int> f[5100];
queue<int> q;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>T;
    while(T--){
    	cin>>n>>d;
    	for(i=1;i<=n;i++) cin>>x[i];
    	if(n<=5000){
	    	for(i=1;i<=n;i++){
	    		f[i].clear();
	    		for(j=1;j<=n;j++){
	    			if(i==j) continue;
	    			if(abs(x[j]-x[i])<=d) f[i].push_back(j);
				}
			}
			cnt=0;
			for(i=1;i<=n-1;i++){
				while(!q.empty()) q.pop();
				q.push(i);
				memset(vis,0,sizeof(vis));
				memset(dis,63,sizeof(dis));
				memset(dic,63,sizeof(dic));
				memset(dik,63,sizeof(dik));
				vis[i]=1;
				dis[i]=0;
				dic[i]=0;
				dik[i]=0;
				while(!q.empty()){
					fx=q.front();
					q.pop();
					for(j=0;j<f[fx].size();j++){
						sx=f[fx][j];
						if(dis[fx]+1<dis[sx]){
							dik[sx]=dic[sx];
							dic[sx]=dis[sx];
							dis[sx]=dis[fx]+1;
							if(!vis[sx]){
								vis[sx]=1;
								q.push(sx);
							}
						}
						else if(dis[fx]+1<dic[sx]){
							dik[sx]=dic[sx];
							dic[sx]=dis[fx]+1;
							if(!vis[sx]){
								vis[sx]=1;
								q.push(sx);
							}
						}
						else if(dis[fx]+1<dik[sx]){
							dik[sx]=dis[fx]+1;
							if(!vis[sx]){
								vis[sx]=1;
								q.push(sx);
							}
						}
					}
				}
				for(j=i+1;j<=n;j++){
					if((dis[j]!=dis[0])&&(dis[j]==dic[j])&&(dic[j]!=dik[j])) cnt++;
				}
			}
			cout<<cnt<<"\n";
		}
		else cout<<d/(x[2]-x[1])<<"\n";
	}
}