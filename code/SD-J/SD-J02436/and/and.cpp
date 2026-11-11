#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
string a1[200005];
int ans;
int maxa=INT_MIN;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxa=max(maxa,a[i]);
	}
	
	if(m==1)
	{
		cout<<maxa;
		return 0;
	}
	
	
	
	
	
	return 0;
}
