#include<bits/stdc++.h>
using namespace std;
long long n,m; 
long long t;
long long a[10010];
long long s[10010],b[10010];
long long ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		 if(m<=n)
		 {
		 	ans++;
		 }
		 else if(m>n)
		 {
		 	for(int j=1;j<=n;j++)
		 	{
		 		t=a[j]+a[j-1];
			 }
			 ans=(t+m)/n;
			 ans=ans/2;
		 }else if(n==m)
		 {
		 	for(int k=0;k<n;k++)
		 	{
		 		t=a[k]+a[k-1];
			 }
			 ans=(t+m)/n;
		 }
	}
	cout<<ans;
	return 0;
}
//Oct31==Dec25?

