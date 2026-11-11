#include <bits/stdc++.h>
using namespace std;
string A[300000];
string ss = "";
long long m,n,sum,sum1;
long long dfs(long long step,long long bo,long long id)
{
	if(id == n + 1 && step < m)
	{
		return -1;
	}
	long long i,j;
	if(step == m + 1)
	{
		for(i = ss.size()-1;i >= 0;i--)
		{
			sum += (ss[i] - '0') * pow(i,2);
		}
		sum1 = max(sum1,sum); 
		return sum1;
	}
	if(bo == 1)
	{
		for(i = 0;i < max(ss.size(),A[id].size());i++)
		{
			if(ss[i] == A[id][i])
			{
				ss[i] = '1';
			} 
			else
			{
				if(ss[i] != A[id][i])
				{
					if((A[id][i] == ' ' && ss[i] == '0') || (A[id][i] == '0' && ss[i] == ' '))
					{
						ss[i] == '1';
					}
					else
					{
						if((A[id][i] == ' ' && ss[i] == '1') || (A[id][i] == '1' && ss[i] == ' '))
						{
							ss[i] == '0';
						}
					}
				}
					
			}
			
		}
	}
	
	string s3 = ss;
	dfs(step + 1,1,id+ 1);
	ss = s3;
	dfs(step,0,id + 1);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long i,j;
	cin >> n >> m;
	for(i = 1;i <= n;i++)
	{
		long long x;
		cin >> x;
		string s = "";
		while(x != 1)
		{
			if(x %2==0)
			{
				s += '0';
				x /= 2;
				continue;
			}
			s += '1';
			x/=2;
		}
		s += '1';
		A[i] = s;
	}
	long long op = max(dfs(0,1,1),dfs(0,1,0));
	
	cout << op; 
	return 0;
} 
