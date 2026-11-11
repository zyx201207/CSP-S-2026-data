#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int N=2e6+10;

int a[N];
int b[5010][5010];

signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	if(c>=11&&c<=12) {
		while(t--) {
			int n,d;
			cin>>n>>d;
			for(int i=1; i<=n; i++) {
				cin>>a[i];
			}
			int cha=a[2]-a[1];
			int maxx=d/cha;
			int len=2*maxx-1;
			if(n+1<len||d<=cha) cout<<0<<endl;
			else cout<<n-len<<endl;
		}
	}
	else if(c>=13&&c<=14){
		while(t--) {
			int n,d;
			cin>>n>>d;
			for(int i=1; i<=n; i++) {
				cin>>a[i];
			}
			int l=1,r=n;
			for(int i=1;i<=n;i++){
				if(a[i]-a[1]<=d&&a[n]-a[i]<=d){
					l=max(l,i);
					r=min(r,i);
				}
			}
			cout<<(l-1)*(n-r)<<endl;
		}
	}
	else{
		while(t--) {
			int n,d;
			cin>>n>>d;
			for(int i=1; i<=n; i++) {
				cin>>a[i];
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+3;j<=n;j++){
					int cha=a[j]-a[i];
					if(cha<=d){
					}
					else{
						int lmin=0;
						int now=i;
						for(int l=i;l<=j;l++){
							if(a[l]-a[now]>d){
								now=l-1;
								lmin++;
							}
						}
						if(now!=j) lmin++;
						if(1){
							ans+=1;
						}
					}
				}
			}
			cout<<ans<<endl;
		}
	}
}
