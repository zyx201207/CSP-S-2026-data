#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+8;
int n,m,a[N],pre[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	int l=0,ans=0;
	for(int i=1;i<=n;i++){
		while(a[i]*(i-l)-(pre[i]-pre[l])>m) l++;
		ans=max(ans,i-l);
	}
	cout<<ans<<'\n';
	return 0;
}
/*
I'm Mingzhou13(681941), I love wxq in FH high school 4ever!
*/
