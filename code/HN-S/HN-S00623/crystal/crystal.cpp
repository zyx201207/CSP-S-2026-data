#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,t,cnt,r;
int a[N],b[N],sumb[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	t=a[2]-a[1];
	r=1;
	while(cnt<m){
		cnt+=t*r;
		r++;
	}
	if(cnt==m) cout<<r;
	else cout<<r-1;
	return 0;
}
