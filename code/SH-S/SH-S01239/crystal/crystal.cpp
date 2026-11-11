#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,l,ans;
long long m,a[500010],sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	l=n;
	while(l>1&&sum+a[n]-a[l-1]<=m)sum+=a[n]-a[--l];
	//cout<<n<<" "<<l<<endl;
	ans=n-l+1;
	for(int i=n-1;i;i--){
		sum-=(i+1-l)*(a[i+1]-a[i]);
		while(l>1&&sum+a[i]-a[l-1]<=m)sum+=a[i]-a[--l];
		ans=max(ans,i-l+1);
		//cout<<i<<" "<<l<<endl;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
