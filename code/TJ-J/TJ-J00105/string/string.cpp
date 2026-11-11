#include <bits/stdc++.h>
using namespace std;
const int N=2*1e5;
const int M=1e9;
int n,sum=0,cnt=0,Mod10=0;
int a[N];
char s[55],S[M];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for (int i =1 ; i <= n; i++)
	{
		cin >> a[i] >> s[i];
		for (int j =1 ; j <= a[i]; j++)
		{
			sum++;
			S[sum]=s[i];
		}
	}
	for (int i =1 ; i <= sum/2; i++)
	{
		if (S[i]!=S[sum-i+1])
		{
			cnt++;
		}
	}
	cout << cnt; 
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
