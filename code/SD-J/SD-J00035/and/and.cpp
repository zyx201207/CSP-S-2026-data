#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N=200010;
int n,m,ans;
int a[N],b[N],cnt;
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int j=30;j>=0;j--){
		cnt=0;
		for(int i=1;i<=n;i++) if((a[i]>>j)&1) b[++cnt]=a[i];
		if(cnt>=m){
			n=cnt;
			for(int i=1;i<=n;i++) a[i]=b[i];
			ans|=(1<<j);
		}
	}
	cout<<ans<<endl;
	return 0;
}
