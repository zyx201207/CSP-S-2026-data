#include<bits/stdc++.h>
using namespace std;
string s="", x;
int m, n;
long long cnt=0, sum;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
		cin>>m>>x;
		sum+=m;
		while(m--)
		{
			s+=x;
		}
	}
	for(int i=0; i<sum/2; i++)
	{
		if(s[i]!=s[sum-1-i])
		{
			cnt++;
		}
	}
	cout<<cnt;
    return 0;
}
