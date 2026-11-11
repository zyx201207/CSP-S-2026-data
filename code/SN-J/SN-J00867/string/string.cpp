#include<bits/stdc++.h>
using namespace std;
int n;
int num[200005];
char cha[200005],x1[1000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> num[i] >> cha[i];
	}
 
	int k = 0;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= num[i];j++)
		{
			k++;
			x1[k] = cha[i];
		}
	}
	
	int cnt = 0; 
	for(int i = 1;i <= k;i++)
	{
		if(x1[i] != x1[k + 1 - i])
		{
			cnt++;
		}
	}
	cout << cnt / 2 << endl;
	return 0;
}


