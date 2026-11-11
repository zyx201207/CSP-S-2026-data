#include<bits/stdc++.h>
using namespace std;
long long int a[2000005],d,ans;
struct node{
	int x,y,step;
};
queue<node> q;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t,c,n;
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		ans=0;
		cin>>n>>d;
		map<string,int> mp;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			q.push({i,i,0});
		}
		while(q.size())
		{
			node t=q.front();
			string s;
			q.pop();
			long long int x1,y1,step1;
			x1=abs(t.x);
			y1=abs(t.y);
			step1=t.step;
			while(x1>0)
			{
				s+=char(x1%10+'0');
				x1=x1/10;
			}
			s+='0';
			while(y1>0)
			{
				s+=char(y1%10+'0');
				y1=y1/10;
			}
			while(step1>0)
			{
				s+=char(step1%10+'0');
				step1=step1/10;
			}
			mp[s]++;
			if(mp[s]==2) ans++;
			else if(mp[s]>2) ans--;
			for(int i=t.y+1;i<=n;i++)
			{
				if(a[i]-a[t.y]<=d)
				{
					q.push({t.x,i,t.step+1});
				}
				else
				{
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;	
} 
