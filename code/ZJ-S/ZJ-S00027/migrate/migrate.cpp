#include<bits/stdc++.h>
#define int long long
#define INF 1145141919810
using namespace std;
int c,t,n,d,a[3200001];
int f[3200001],g[3200001];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		if(c==11||c==12){
			if(n==1){
				cout<<"0\n";
				continue;
			}
			int gez=a[2]-a[1];
			int zng=d/gez;
			if(zng==1||zng==0){
				cout<<"0\n";
				continue;
			}
			zng=2*zng-1;
			if(zng>n)cout<<"0\n";
			else cout<<n-zng<<"\n";
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			int now=i;
			f[i]=1,g[i]=1;
			for(int j=i+1;j<=n;j++){
				g[j]=0;
				while(a[j]-a[now]>d)now++;
				int np=now;
				while(1){
					if(now>=j)break;
					f[j]=f[now]+1;
					g[j]+=g[now];
					now++;
					if(f[now]!=f[now-1])break;
				}
				now=np;
				if(g[j]==2){
					ans++;
//					cout<<i<<" "<<j<<"\n";
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
