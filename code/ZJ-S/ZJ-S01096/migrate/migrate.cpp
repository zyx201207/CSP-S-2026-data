#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,d,i,dx,x[2000010],u,v,sum,u1,u2,ans=0,t,bao;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;ans=0;
		for(i=1;i<=n;i++) cin>>x[i];
		for(u=1;u<=n-2;u++){
			for(v=u+2;v<=n;v++){
				if(x[u]+d>=x[v]) continue;
				t=u;
				dx=x[v]-d;
				while(1){
					sum=0;
					u1=x[t]+1;
					u2=x[t]+d;
					if(u1>=dx){
						for(i=t+1;i<v;i++)
							if(u1<=x[i]&&x[i]<=u2) sum++;
						if(sum==2) ans++;
						break;
					}
					else if(u1<dx&&u2>=dx){
						for(i=t+1;i<v;i++)
							if(dx<=x[i]&&x[i]<=u2) sum++;
						if(sum==2) ans++;
						break;
					}
					else{
						bao=t;
						for(i=v;i>=t;i--)
							if(x[i]<=u2){
								t=i;break;	
							}
						if(bao==t) break; 
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

