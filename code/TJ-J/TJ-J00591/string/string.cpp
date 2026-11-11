#include<bits/stdc++.h>
using namespace std;
int a[200010];
string c[20010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt = 0;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
	{
		string l;
		cin >> a[i] >> l;
		for(int j = 1;j <= a[i];j++)
		{
			c[i]+=l;
		}
			string m = c[i];
		for(int k=0;k<a[i]/2;k++)
		{
			char b = m[k];
			char d = m[a[i]-k];
			if(b != d)
			{
				cnt++;
			}
			
		}
		
	}
	cout << cnt;
	return 0;
}
