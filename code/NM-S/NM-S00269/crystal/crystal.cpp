#include<bits/stdc++.h>
using namespace std;
const int M=1e5+10;
long long n,m,ans=-2e9;
long long a[5*M],f[5*M];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	 cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)
		f[i]=a[i]-a[i-1];
    for(int i=1;i<=n;i++)
     {
     	long long sum=m,cnt=1;
     	for(int j=i+1;j<=n;j++)
      	    if(sum>=f[j]) {
      	    	            sum-=f[j];
      	    	            cnt++;
			              }
			         else break;
	    ans=max(ans,cnt);
	 }
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
