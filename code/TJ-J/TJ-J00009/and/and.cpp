#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],maxn;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(m==1){
		for(int i=0;i<n;i++)
		{
			maxn=max(a[i],maxn);
		}
		cout<<maxn<<endl;
		return 0;
	}
	else if(m==2){
	maxn=a[1]&a[0];
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn<<endl;
		return 0;
	}
	else if(m==n)
	{
		for(int i=0;i<n;i++)
		{
			maxn&=a[i];
		}
		cout<<maxn<<endl;
		return 0;
	}else{
		sort(a,a+n,greater<int>());
		for(int i=0;i<n;i++)
		{
			cout<<a[i]<<' ';
		}
		cout<<a[m];
	}
	return 0;
}
