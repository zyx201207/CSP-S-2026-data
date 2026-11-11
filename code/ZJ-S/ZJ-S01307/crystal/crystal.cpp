#include<bits/stdc++.h>
using namespace std;
int n,ans=1;
long long m,a[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("ctystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1,j=2,sum=0;j<=n;j++){
		sum+=(a[j]-a[j-1])*(j-i);
		while(sum>m)sum-=a[j]-a[i++];
		ans=max(ans,j-i+1);
	}cout<<ans;
	return 0;
}
