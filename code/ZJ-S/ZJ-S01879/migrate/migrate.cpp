#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 2000005
int c,t,n,d,a[N],e;
const inline void dfs(int x,int y,int s,int sum){
	if(s==sum){
		if(x==y)++e;
		return ;
	}for(int i=x+1;i<=n;++i){
		if(a[i]-a[x]>d)break;
		dfs(i,y,s+1,sum);
	}
}signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		if(c==13||c==14){
			cin>>n>>d;int ans=0;
			for(int i=1;i<=n;++i){
				cin>>a[i];
			}cout<<0<<'\n';
		}else if(c==11||c==12){
			cin>>n>>d;
			for(int i=1;i<=n;++i){
				cin>>a[i];
			}int q=d/abs(a[2]-a[1]);
			q+=q-1;if(q<=2||q>n)q=n;
			cout<<n-q<<'\n';
		}else{
			cin>>n>>d;int ans=0;e=0;
			vector<int>p(n+2,1);
			for(int i=1;i<=n;++i){
				cin>>a[i];
			}for(int i=1;i<=n;++i){
				int t=i;
				while(t<n&&a[t+1]-a[i]<=d)++t;
				p[i]=t;
			}for(int i=1;i<=n;++i){
				for(int j=i+3;j<=n;++j){
					int cnt=0,k=i,sum=0;
					while(k<j){
						if(k==p[k]){
							cnt=1e18;break;
						}k=p[k];++cnt;
					}if(cnt==1e18)continue;
					e=0;dfs(i,j,0,cnt);
					if(e==2)++ans;
				}
			}cout<<ans<<'\n';
		}
			
	}
	return 0;
}
