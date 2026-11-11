#include <bits/stdc++.h>
using namespace std;
int n,m;
bool have[300005];
int res[300005],c[500005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	stack <int> s; 
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i = 0;i < n;i++) scanf("%d",&c[i]);
    for(int i = 0;i < n;i++)
    {
    	for(int j = i;j < n;j++)
    	{
    		if(have[c[j]])
    		{
    			while(!s.empty() && s.top() != c[j])
    			{
    				have[s.top()] = false;
    				s.pop();
				}
			}
			else
			{
				s.push(c[j]);
				have[c[j]] = true;
			}
		}
		while(!s.empty())
		{
			res[s.top()]++;
			have[s.top()] = false;
			s.pop();
		}
	}
	for(int i = 1;i <= m;i++)
	{
		cout << res[i] << ' ';
	} 
    return 0;
}

