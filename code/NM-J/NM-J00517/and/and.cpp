#include<bits/stdc++.h>
using namespace std;
int a[200010],n,m,maxa;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++)
	 for(j=i+1;j<=n;j++)
	 {
		 if(a[i]==a[j])
		 {
			 cout<<a[i];
			 break;
		 }
	 }
	return 0;
}
