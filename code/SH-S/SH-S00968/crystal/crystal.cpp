#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],sum,ans=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int j=1;
	for(int i=2;i<=n;i++){
		sum+=a[i-1];
		while(a[i]*(i-j)-sum>m&&j<i) sum-=a[j],j++;
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}
