#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
long long a[N],c[N],pre[N],pre2[N];
bool cmp(const int& x,const int& y){return x<y;}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=n;i++)
		c[i]=a[i]-a[i-1];
	for(int i=n;i>=2;i--) pre[i]=pre[i+1]+c[i];
	for(int i=n;i>=2;i--) pre2[i]=pre2[i+1]+pre[i];
	int l=n,r=n,ans=0;
	while(l<=r&&l>1&&r>1){
		while(pre2[l]-pre2[r+1]-pre[r+1]*(r-l+1)<=m&&l>1) l--;
		ans=max(ans,r-l+1);
		r--;
	}
	cout<<ans;
	return 0;
}
