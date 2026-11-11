#include<bits/stdc++.h>
using namespace std;
const int N = 200006;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long int n,t;
	long long int res = 0;
	char data;
	long long int pos = 0;
	cin >> n;
	
	char s[N];
	for(int i = 0;i < n;i++)
	{
		cin >> t >> data;
		for(int j = 0;j < t;j++) 
		{
			s[pos] = data;
			pos++;
		}
	}
	long long int mid = pos / 2;
	long long int  q = mid;
	while(q <= pos - 1)
	{
		if(s[q] != s[pos - 1 - q]) res++;
		q++;
	}
	cout << res;
	return 0;
}