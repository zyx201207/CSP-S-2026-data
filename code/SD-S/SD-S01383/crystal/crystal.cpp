#include<bits/stdc++.h>
#define int long long
const int N=5e5+5;
using namespace std;
int n,m,ans;
int a[N],d[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int cur=0;
	for(int i=2,j=1;i<=n;i++){
		d[i]=d[i-1]+a[i]-a[i-1];
		cur+=(i-j)*(a[i]-a[i-1]);
		while(cur>m) cur-=d[i]-d[j],j++;
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}
/*
ÅÅÐò
*/
