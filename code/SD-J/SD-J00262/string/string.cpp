#include <bits/stdc++.h> 
using namespace std;
const int N = 2e+5;
int n,m,a[N],L,k,ans=0;
char c[N];
stack<pair<int,char> > s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        char y;
        cin>>x>>y;
        if(c[k]==y)
        {
        	a[k]+=x;
		}
		else
		{
			c[++k]=y;
			a[++k]+=x;
		}
		L+=x;
	}
	if(L==1)
	{
		cout<<0;
		return 0;
	}
	int cnt=0;
	if(L%2==1)
	{
		for(int i=1;i<=n;i++)
		{
			cnt+=a[i];
			if(cnt>=(L+1)/2)
			{
				a[i]--;
				break;
			}
		}
		L--;
	}
    int i=1;
    cnt=0;
    while(cnt<L/2&&i<=k)
    {
    	if(a[i]==0)
		{
			continue;
		}
    	if(cnt+=a[i]<=L/2)
    	{
    		s.push(make_pair(a[i],c[i]));
    		cnt+=a[i];
    		i++;
		}
		else
		{
			s.push(make_pair(L/2-cnt,c[i]));
			cnt=L/2;
			a[i]-=(L/2-cnt);
			break;
		}
	}
	while(i<=k&& !s.empty())
	{
		if(s.top().second==c[i])
		{
			if(s.top().first==a[i])
			{
				ans+=a[i];
				s.pop();
				i++;
			}
			else if(s.top().first<a[i])
			{
				ans+=a[i];
				s.top().first-=a[i];
				i++;
			}
			else
			{
				a[i]-s.top().first;
				s.pop();
			}
		}
		else
		{
		    if(s.top().first==a[i])
			{
				ans+=a[i];
				s.pop();
				i++;
			}
			else if(s.top().first<a[i])
			{
				ans+=a[i];
				s.top().first-=a[i];
				i++;
			}
			else
			{
				a[i]-s.top().first;
				s.pop();
			}	
		}
	}
	cout<<ans;
    return 0;
}
