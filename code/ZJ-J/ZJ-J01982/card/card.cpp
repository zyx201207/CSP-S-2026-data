#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],b[N],ans[N],s[N],top;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=n;++i){
		top=0;
		for(int j=i;j<=n;++j){
			if(b[a[j]]!=0){
				while(s[top]!=a[j]){
					b[s[top]]=0;
					top--;
				}
			}
			else s[++top]=a[j],b[a[j]]=1;
		}
		for(int j=1;j<=top;++j) ans[s[j]]++,b[s[j]]=0;
	}
	for(int i=1;i<=m;++i) cout<<ans[i]<<" ";
}
