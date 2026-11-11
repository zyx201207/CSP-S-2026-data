#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
int n;
ll d,x[N];
void solve(){
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;i++){
		scanf("%lld",&x[i]);
	}
	ll ans=0;
	for(int r=1;r<=n;r++){
		for(int l=1;l<=r;l++){
			int lpos=l;
			bool flag=0;
			for(int i=l;i<=r;i++){
				int pos=i;
				while(pos<=r&&x[pos]-x[i]<=d){
					pos++;
				}
				pos--;
				if(lpos>i&&lpos<pos){
					if(flag){
						flag=0;
						break;
					}
					flag=1;
				}
				lpos=pos;
			}
			if(flag){
				ans++;
			}
		}
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T=1,C;
	scanf("%d%d",&C,&T);
	while(T--){
		solve();
	}
}
//ccf please let me AC!!!
