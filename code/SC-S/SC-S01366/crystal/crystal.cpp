//crystal
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+10;
int n,m,a[N],p[N],l,ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	l=1;
	for(int i=1;i<=n;++i){
		p[i]=p[i-1]+a[i];
		if(a[i]!=a[i-1]){
			while((i-l)*a[i]-(p[i-1]-p[l-1])>m){
				++l;
			}
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}