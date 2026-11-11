#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t,n;
ll d,x[2000006],dis[2000006],fangan[2000006],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int u=1;u<=n;u++){
			dis[u]=0;
			for(int i=u+1;i<=n;i++){
				dis[i]=LONG_LONG_MAX;
				for(int j=i-1;j>=u;j--){
					if(x[i]-x[j]<=d) dis[i]=min(dis[i],dis[j]+1);
					else break;
				}
			}
			fangan[u]=1;
			for(int v=u+1;v<=n;v++){
				fangan[v]=0;
				for(int k=u;k<v;k++){
					if(x[v]-x[k]<=d) fangan[v]+=fangan[k];
				}
				if(fangan[v]==2) ans++;
			}
		}
		cout<<ans-1<<"\n";
	}
	return 0;
}
