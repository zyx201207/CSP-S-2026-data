#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int k=i+1;k<=n;k++)
		{
			int num=a[i];
			for(int j=k;j<=k+m-2;j++)
			{
				num=num&a[j];
			}
			if(ans<num)
			{
				ans=num;
			}
		}
		
	}
	cout<<ans;
	return 0;
} 
