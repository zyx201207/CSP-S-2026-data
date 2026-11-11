#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500100;
int n,m,res,a[N],s[N];
int calc(int l,int r){return (r-l+1)*a[r]-(s[r]-s[l-1]);}
signed main(){
	freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1,p=1;i<=n;i++){
		while(p<i&&calc(p,i)>m) ++p;
		res=max(res,i-p+1);
	}
	return cout<<res<<'\n',0;
}