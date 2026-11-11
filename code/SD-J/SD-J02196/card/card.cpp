#include<bits/stdc++.h>
#define gcd(x,y) __gcd(x,y)
#define lcm(x,y) (x/gcd(x,y)*y)
using namespace std;
int a[500005],b[500005],ans[300005];
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int len=0;
		for(int j=i;j<=n;j++){
			int flag=1;
			for(int k=len;k>0;k--){
				if(b[k]==a[j]){
					len=k;
					flag=0;
				}
			}
			if(flag){
				b[++len]=a[j];
			}
		}
		for(int j=1;j<=len;j++){
			ans[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}

