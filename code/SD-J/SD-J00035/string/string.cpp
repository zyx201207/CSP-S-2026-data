#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N=200010;
struct node{
	ll len;
	char c;
}a[N];
ll l[N],r[N],n,ans;
ll y[N*4],cnt;
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	a[0].len=0;l[0]=1;
	for(int i=1;i<=n;i++) cin>>a[i].len>>a[i].c;
	for(int i=1;i<=n;i++) l[i]=l[i-1]+a[i-1].len,r[i]=l[i]+a[i].len-1;
	for(int i=1;i<=n;i++){
		y[++cnt]=l[i];
		y[++cnt]=r[i];
		y[++cnt]=r[n]-l[i]+1;
		y[++cnt]=r[n]-r[i]+1;
	}
	sort(y,y+cnt);cnt=unique(y,y+cnt)-y-1;
	for(int i=1;i<=cnt;i++){
		int t1=upper_bound(l+1,l+1+n,y[i])-l-1;
		int t2=upper_bound(l+1,l+1+n,r[n]-y[i]+1)-l-1;
		if(a[t1].c!=a[t2].c) ans+=y[i]-y[i-1];
	}
	cout<<ans/2<<endl;
	return 0;
}
