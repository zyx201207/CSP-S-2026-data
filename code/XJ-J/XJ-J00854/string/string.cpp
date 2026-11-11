#include<bits/stdc++.h>
using namespace std;
long long n;
int a[1000];
int f = 0;
char s1[1000],s2;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i] >> s1[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(s1[i] == s1[i+1]) f = 1;
		else f = 0;
	}
	if(f = 1)
	{
		cout << 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}