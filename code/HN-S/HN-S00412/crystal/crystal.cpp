#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,z[N],s[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>z[i];
	sort(z+1,z+n+1);
	for(int i=1;i<=n;++i)s[i]=s[i-1]+z[i];
	for(int i=1;i<=n;++i){
		int l=0,r=i-1,mid;
		while(l<r){
			mid=(l+r)>>1;
			if(z[i]*(i-mid)-s[i]+s[mid]<=m)r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l);
	}
	cout<<ans;
	return 0;
}
