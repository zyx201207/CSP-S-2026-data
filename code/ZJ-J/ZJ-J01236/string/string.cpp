#include<bits/stdc++.h>
using namespace std;
int n;
int a[200020];
char c[200020];

string x;
long long cnt = 0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	bool f = 0;
	
	for (int i = 1;i <= n;i ++)
	{
		cin>>a[i]>>c[i];
		if (i > 1)if (c[i] != c[i - 1])f = 1;
	}
	if (f == 0)
	{
		cout<<0;
		return 0;
	}
	int l = 1;
	int r = n;
	while (l <= r)
	{
//		cout<<l<<" "<<r<<" "<<a[l]<<" "<<a[r]<<" "<<cnt<<endl;
		if (a[l] < a[r])
		{
			if (c[l] != c[r])
			{
				cnt += a[l];a[r] -= a[l];
				l ++;
				
			}
			else
			{a[r] -= a[l];
				l ++;
				
			}
		}
		else
		{
			if (c[l] != c[r])
			{
				cnt += a[r];a[l] -= a[r];
				r --;
				
			}
			else
			{
				a[l] -= a[r];
				r --;
			}
		}
	}
	cout<<cnt;
	return 0;
}