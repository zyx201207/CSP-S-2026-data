#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
string c[200005];
int main()
{
	freopen("string.in",r,stdin);
    freopen("string.out",w,stdout);
    string b,d;
    int bl = 0;
    int nd = 0;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
		cin >> a[i] >> c[i];
	}
	for(int i = 1;i <= n;i++)
    {
		for(int j = 1;j <= a[i];j++)
    	{
			b += c[i];
		}
	}
	for(int i = b.size() - 1;i >= 0;i--)
    {
		d += b[i];
	}
	for(int i = 1;i <= b.size() - 1;i++)
	{
		if(b[i] == d[i])
		{
			bl = 1;
		}
		else
		{
			bl = 0;
			nd += 1;
		}
	}
	if(bl == 1)
	{
		cout << 0 << endl;
	}
	else
	{
		cout << nd << endl;
	}
    return 0;
}
