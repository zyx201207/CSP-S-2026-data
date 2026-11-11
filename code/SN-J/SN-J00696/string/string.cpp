//陈宇轩 西安市第八十九中学 SN-J00696 
#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans=0;
string x,y;
bool flag;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i=0;i<n;i++)
	{
		cin >> a[i] >> x;
		for(int j=0;j<a[i];j++)
		{
			y+=x;
		}
	}
	flag=true;
	for (int i=1;i<=n;i++)
	{
		if (y[i]==y[n-i+1])
		{
			flag=true;
		}
		else
		{
			flag=false;
			ans++;
		}
	}
	
	cout << ans;
	return 0;
}

