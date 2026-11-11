#include <bits/stdc++.h>
using namespace std;
int n,m,maxa=0;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >>m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	if(m==1)
	{
		cout << 0;
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				maxa=max(maxa,a[i]&a[j]);
				
			}
		}
		cout << maxa;
		return 0;
	}
	if(m==3)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int z=j+1;z<=n;z++){
				
					maxa=max(maxa,a[i]&a[j]&a[z]);
				}
			}
		}
		cout << maxa;
		return 0;
	}
	if(m==4)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int z=j+1;z<=n;z++){
					for(int i1=z+1;i1<=n;i1++){
					
						maxa=max(maxa,a[i]&a[j]&a[z]&a[i1]);
					}
				}
			}
		}
		cout << maxa;
		return 0;
	}
	if(m==5)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int z=j+1;z<=n;z++){
					for(int i1=z+1;i1<=n;i1++){
						for(int i2=i1+1;i2<=n;i2++)
							maxa=max(maxa,a[i]&a[j]&a[z]&a[i1]&a[i2]);
					}
				}
			}
		}
		cout << maxa;
		return 0;
	}
	if(m==6)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int z=j+1;z<=n;z++){
					for(int i1=z+1;i1<=n;i1++){
						for(int i2=i1+1;i2<=n;i2++)
							for(int i3=i2+1;i3<=n;i3++)
							maxa=max(maxa,a[i]&a[j]&a[z]&a[i1]&a[i2]);
					}
				}
			}
		}
		cout << maxa;
		return 0;
	}
	if(m==7)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int z=j+1;z<=n;z++){
					for(int i1=z+1;i1<=n;i1++){
						for(int i2=i1+1;i2<=n;i2++)
							for(int i3=i2+1;i3<=n;i3++)
							for(int i4=i3+1;i4<=n;i4++)
							maxa=max(maxa,a[i]&a[j]&a[z]&a[i1]&a[i2]);
					}
				}
			}
		}
		cout << maxa;
		return 0;
	}
	if(m==8)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int z=j+1;z<=n;z++){
					for(int i1=z+1;i1<=n;i1++){
						for(int i2=i1+1;i2<=n;i2++)
							for(int i3=i2+1;i3<=n;i3++)
							for(int i4=i3+1;i4<=n;i4++)
							for(int i5=i4+1;i5<=n;i5++)
							maxa=max(maxa,a[i]&a[j]&a[z]&a[i1]&a[i2]);
					}
				}
			}
		}
		cout << maxa;
		return 0;
	}
	if(m==n)
	{
		int x;
		for(int i=1;i<=n;i++)
		{
			x=x&a[i];
		}
		cout << x;
		return 0;
	}
	if(m=n-1)
	{
		for(int i=1;i<=n;i++)
		{
			int x;
			for(int j=1;j<=n;j++)
			{
				if(j==i) continue;
				x=x&a[j];
			}
			maxa=max(x,maxa);
		}
		cout << maxa ;
		return 0;
	}
	return 0;
}
