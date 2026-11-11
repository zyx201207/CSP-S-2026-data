#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m,a[N],maxx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m==1)
	{
		sort(a+1,a+1+n);
		cout<<a[n];
		return 0;	
	}
	cout<<0;
	return 0;
} 
