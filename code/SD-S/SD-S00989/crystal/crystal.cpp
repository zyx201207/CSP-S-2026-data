#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m;
int a[N];
int ans=0;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	a[0]=a[1];
	int l=1,last=0;
	unsigned long long sum=0;
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]) continue;
		sum+=(last-l+1)*(a[i]-a[last]);
		while(sum>m) sum-=a[i]-a[l],l++;
		ans=max(ans,i-l+1);
	//	cout<<i<<" "<<l<<" "<<sum<<"\n";
		last=i;
	}
	cout<<ans;
	return 0;
}

