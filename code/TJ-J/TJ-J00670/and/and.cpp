#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i<n;i++)
	{
		cin >> a[i];
	}
	if(m==2)
	{
		int max_ = 0;
		for(int i = 0;i<n;i++)
		{
			for(int j = i+1;j<n;j++)
			{
				if((a[i]&a[j])>max_)
				{
					max_ = (a[i] & a[j]);
				}
			}
		}
		cout << max_<< endl;
	}
	else
	{
		sort(a,a+n,cmp);
		int and_ = a[0];
		for(int i = 0;i<m;i++)
		{
			and_ = (and_&a[i]);
		}
		cout << and_ << endl;
	}
	return 0;
} 
