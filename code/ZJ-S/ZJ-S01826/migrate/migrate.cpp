#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long x[N];
struct S{
	int stp,cnt;
}f[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n;
		long long d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(c<=10){
			int ans=0;
			for(int i=1;i<=n;i++){
				f[i]={0,1};
				for(int j=i+1;j<=n;j++){
					int p=lower_bound(x+1,x+n+1,x[j]-d)-x;
					p=max(p,i);
					if(p==j) break;
					f[j]={f[p].stp+1,f[p].cnt};
					int cnt=1;
					while(p+1<j && f[p+1].stp==f[p].stp){
						f[j].cnt+=f[++p].cnt;
						if(cnt>2) break;
					}
					if(f[j].cnt==2) ans++;
				}
			}
			cout<<ans<<'\n';
		}
		else{
			long long num=d/(x[2]-x[1]);
			if(num<=1) cout<<0<<'\n';
			else cout<<max(0ll,n-num*2+1)<<'\n';
		}
	}
	return 0;
}
