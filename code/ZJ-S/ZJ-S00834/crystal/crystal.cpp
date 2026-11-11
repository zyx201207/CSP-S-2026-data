#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int sum[N],n,m,a[N],ans[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=a[i]+sum[i-1];
	}
	sort(a+1,a+n+1);
	int cnt=0,fians=0;
	ans[1]=1;
	for(int i=2,j=1;i<=n;i++){
		cnt=cnt+ans[i-1]*(a[i]-a[i-1]);
		while(cnt>m&&j<i) cnt-=a[i]-a[j],j++;
		ans[i]=i-j+1;
		fians=max(fians,ans[i]);
	}
	cout<<fians;
	return 0;
}
