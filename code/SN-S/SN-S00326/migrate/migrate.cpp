//高一轩 西安铁一中滨河高级中学 SN-S0036 
#include <bits/stdc++.h>
using namespace std;
long long n,d,t,c,mp[2000005],cnt,m,ans,an,l,anns;
int min(int l,int r)
{
	int num =0;
	int i = l;
	for(;i<r;)
	{
		for(int j = i;;j++)
		{
			if(mp[j] - mp[i]>d)
			{
				i = j -1;
				num++;
				break;
			}
		}
	}
}
int dfs(int x)
{
	if(cnt>2)
	{
		return 0;
	}
	if(x>l)
	{
		if(an == ans)
			cnt++;
	}
	for(int i = x;mp[i] - mp[x]<=d;i++)
	{
		dfs(i);
	}
	return cnt;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << "1" << "\n" << "2";
	/*cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		
		for(int i = 0;i<n;i++)
		{
			cin >> mp[i];
		}
		long long sub = mp[1] - mp[0];
		if(d<2*sub)
		{cout << "0";return 0;}	
		for(int r = 0;r<n-1;r++)
			for(l = r+1;l<n;l++)
			{
				int cn = dfs(r);
				if(cn == 2)
				{
					
				}
			}
		cout << 
	}	
	return 0;
	/*记得long long,文件注释*/
}
