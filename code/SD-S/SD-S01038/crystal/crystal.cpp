#include<iostream>
#include<algorithm>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long l=1,cost=0,ans=0;
	for(int i=1;i<=n;i++){
		cost+=(i-l)*(a[i]-a[i-1]);
		while(cost>m) cost-=a[i]-a[l++];
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
} 
