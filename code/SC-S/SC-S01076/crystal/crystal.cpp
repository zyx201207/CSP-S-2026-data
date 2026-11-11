#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
const int inf=1e9+7;
int n,a[N],pre[N],m;
inline int get(int l,int r,int now){
	return now*(r-l+1)-(pre[r]-pre[l-1]);
}
inline void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	int ans=0;
	for(int i=1,j=1;i<=n;i++){
		while(j<i&&get(j,i,a[i])>m)j++;
		ans=max(ans,i-j+1);
	}
	cout<<ans<<'\n';
}
signed main (){
//	system("fc crystal.out crystal4.ans");
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int Case=1;//cin>>Case;
	while(Case--)solve();
	return 0;
}