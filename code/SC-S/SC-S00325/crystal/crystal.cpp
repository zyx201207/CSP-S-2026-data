#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5*1e5+10;
int a[N],c[N],d[N];
int n,m,ans=-1;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) d[i]=d[i-1]+a[i];
    int l=1,r=1,poiu;
    while(r<=n){
    	poiu=(r-l)*a[r]-(d[r-1]-d[l-1]);
    	if(poiu<=m) r++;
    	if(poiu>m) ans=max(ans,r-l),l++;
	}
	cout<<ans;
	return 0;
}