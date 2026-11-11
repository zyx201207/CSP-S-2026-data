#include<bits/stdc++.h> 
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N],ans;
int idx=0,start[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int last=a[1],dj=0,ilast=1;
	for(int i=1;i<=n;i++){
		if((a[i]-last)*(i-1)+dj<=m)dj+=(a[i]-last)*(i-1),last=a[i];
		else{
			ans=max(i-ilast,ans);
			while((a[i]-last)*(i-1)+dj>m)ilast++,dj-=a[i]-a[ilast];
//			cout<<a[315275]<<' '<<a[i-1];
		}
	}
	cout<<ans;
	return 0;
}