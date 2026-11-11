#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=2e6+1;
int c,t;
int n,d;
int x[MAXN];
int ans;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			ans=0;
			for(int i=1;i<=n;++i){
				cin>>x[i];
			}
			int dif=x[2]-x[1];
			d/=2;
			if(d<dif){
				cout<<0;
				continue;
			}
			for(int i=1;i<=n;++i){
				ans+=((n-i)/dif-d)*d+(n-1)%dif;
			}
			cout<<ans<<'\n';
		}
	}else if(c==13||c==14){
		while(t--){
			cin>>n>>d;
			ans=0;
			for(int i=1;i<=n;++i){
				cin>>x[i];
			}
			for(int i=1;i<=n;++i){
				if(x[i]-x[1]<=d&&x[n]-x[i]<=d){
					cout<<(i-1)*(n-i)<<'\n';
				}
			}
		}
	}else{
		while(t--){
			cout<<0<<'\n';
		}
	}
	return 0;
}
