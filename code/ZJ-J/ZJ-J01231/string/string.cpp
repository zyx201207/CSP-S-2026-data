#include<bits/stdc++.h>
using namespace std;
const long long N = 2e5;
char c[N+10];
long long a[N+10],n,ans,L,len;
vector<pair<char,long long>> l,r;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)    cin >> a[i] >> c[i];
	for(int i = 1; i <= n; i++)    L+=a[i];
	if(L%2==1)
	{
		for(int i = 1; i <= n; i++)
		{
			long long last = len;
			len+=a[i];
			if(len>=L/2)
			{
				if(len==L/2)
				{
					l.push_back(make_pair(c[i],a[i]));
					r.push_back(make_pair(c[i+1],a[i+1]-1));
					for(int j = i+2; j <= n; j++)    r.push_back(make_pair(c[j],a[j]));
				}    
				else
				{
					l.push_back(make_pair(c[i],L/2-last));
					r.push_back(make_pair(c[i],a[i]-1-(L/2-last)));
					for(int j = i+1; j <= n; j++)    r.push_back(make_pair(c[j],a[j]));
				}
				break;
			}
			l.push_back(make_pair(c[i],a[i]));
		}
	}
	else
	{
		for(int i = 1; i <= n; i++)
		{
			long long last = len;
			len+=a[i];
			if(len>=L/2)
			{
				if(len==L/2)
				{
					l.push_back(make_pair(c[i],a[i]));
					for(int j = i+1; j <= n; j++)    r.push_back(make_pair(c[j],a[j]));
				}    
				else
				{
					l.push_back(make_pair(c[i],L/2-last));
					r.push_back(make_pair(c[i],a[i]-(L/2-last)));
					for(int j = i+1; j <= n; j++)    r.push_back(make_pair(c[j],a[j]));
				}
				break;
			}
			l.push_back(make_pair(c[i],a[i]));
		}
	}
	reverse(r.begin(),r.end());
	while(!r.empty() && !l.empty())
	{
		pair<char,long long> cur1 = l.back();
		pair<char,long long> cur2 = r.back();
		if(cur1.first==cur2.first)
		{
			if(cur1.second<=cur2.second)
			{
				l.pop_back();
				r.pop_back();
				cur2.second-=cur1.second;
				r.push_back(cur2);
			}
			else
			{
				l.pop_back();
				r.pop_back();
				cur1.second-=cur2.second;
				l.push_back(cur1);
			}
		}
		else if(cur1.second<=cur2.second)
		{
			ans+=cur1.second;
			l.pop_back();
			r.pop_back();
			cur2.second-=cur1.second;
			r.push_back(cur2);
		}
		else
		{
			ans+=cur2.second;
			l.pop_back();
			r.pop_back();
			cur1.second-=cur2.second;
			l.push_back(cur1);
		}
	}
	cout << ans;
	return 0;
}
