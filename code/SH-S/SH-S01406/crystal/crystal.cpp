#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
#define int long long
int n,m,a[N],ans,pre[N];
bool check(int x){
	int sum=0;
	for(int i=1;i<=n-x;i++)
		if(pre[i+x-1]-pre[i-1]+m>=a[i+x-1]*x)
			return 1;
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		pre[i]=a[i]+pre[i-1];
	int t=1,w=n;
	while(t<=w){
		int mid=(t+w)>>1;
		if(check(mid)) ans=mid,t=mid+1;
		else w=mid-1;
	}
	cout<<ans;
}
