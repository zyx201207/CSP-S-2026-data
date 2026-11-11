#include<bits/stdc++.h>
using namespace std;
const int N = 2e6;
int n;
int a[N]; 
char c[N];
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int l = 1,r = n;
	while(l < r)
	{
		if(c[l] != c[r])
		{
			if(a[l] > a[r])
			{
				ans += a[r];
				a[l] -= a[r];
				a[r] = 0;
				r--;
			}
			else if(a[l] < a[r])
			{
				ans += a[l];
				a[r] -= a[l];
				a[l] = 0;
				l++;
			}
			else if(a[l] == a[r])
			{
				ans += a[l];
				l++;
				r--;
			}
		}
		else
		{
			if(a[l] > a[r])
			{
				a[l] -= a[r];
				a[r] = 0;
				r--;
			}
			else if(a[l] < a[r])
			{
				a[r] -= a[l];
				a[l] = 0;
				l++;
			}
			else if(a[l] == a[r])
			{
				l++;
				r--;
			}			
		}
		
	}
	cout<<ans;
	return 0;
}
