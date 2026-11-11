#include<bits/stdc++.h>
using namespace std;
const int M=1e5+10;
int n,m,ans; 
int a[2*M];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	 cin>>a[i];
	sort(a+1,a+1+n,greater<int>());
	if(m==1) {
	    for(int i=1;i<=n;i++)
	     ans=max(ans,a[i]%a[i]);
	}
	if(m==2) {
		for(int i=1;i<=n;i++)
		 for(int j=1;j<=n;j++)
		  ans=max(ans,a[i]%a[j]);
	}
	cout<<ans;
 	fclose(stdin);
	fclose(stdout);
	return 0;
}
