#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,d,a[2000005],ans,dis[305][305];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(c<=6){ //n<=300 
			ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					int fcnt=0,t=0;
					for(int k=i;k<=j;k++) for(int u=k+1;u<=j;u++)
						for(int v=u+1;v<=j;v++) for(int w=v+1;w<=j;w++){
							int x=a[k],y=a[u],z=a[v],W=a[w]; if(z-x<=d&&W-y<=d&&W-x>d) fcnt++,t=k;}
					for(int k=i+1;k<=j;k++) if(a[k]-a[k-1]>d) fcnt=0;
					if(fcnt==1) ans++;
				}
			}cout<<ans<<'\n';
		}else if(c==12||c==11){
			int del=a[2]-a[1];
			if(2*del<=d) cout<<max(0ll,n-2*d/del+1);
			else cout<<0; cout<<'\n';
		}
	}
}
