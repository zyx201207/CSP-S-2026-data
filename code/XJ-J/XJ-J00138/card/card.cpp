#include<bits/stdc++.h>
using namespace std;
int s[100];
int main()
{
	int n,m,cnt;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		l=s.lend;
		for(int f=0;f<=n;f++)
		{
			if(s[f]==s[f+1])
			{
				earse.s(s[f+1],s[l-1]);
				cnt++;
			}
		}
		cout<<cnt;
	}
	return 0;
}
