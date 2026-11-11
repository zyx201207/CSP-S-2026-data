#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
int c,t,n;
ll dd,xs[N],cnt;
struct Node
{
	int a,b,c,d;
};
queue<Node>q;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>t;
	while(t--)
	{
		cnt=0;
		while(q.size())
		{
			q.pop();
		}
		cin>>n>>dd;
		for(int i=1;i<=n;i++)
		{
			cin>>xs[i];
		}
		if(n<=3)
		{
			cout<<"0\n";
			continue;
		}
		for(int i=1;i<=n-3;i++)
		{
			if(xs[i+3]-xs[i]>dd&&xs[i+3]-xs[i+1]<=dd&&xs[i+2]-xs[i]<=dd)
			{
				cnt++;
				q.push({i,i+1,i+2,i+3});
			}
		}
		if(n==4)
		{
			cout<<cnt<<"\n";
			continue;
		}
		while(q.size())
		{
			Node t=q.front();
			q.pop();
			int a=t.a,b=t.b,c=t.c,d=t.d;
			if(xs[c]+dd<=xs[n])
			{
				int l=d+1;
				while(xs[l]-xs[c]<=dd)
				{
					l++;
				}
				for(int i=l;i<=n&&xs[i]-xs[d]<=dd;i++)
				{
					cnt++;
					q.push({a,b,c,i});
				}
			}
			for(int i=d+1;i<=n&&xs[i]-xs[b]<=dd;i++)
			{
				q.push({a,b,c,i});
			}
			if(xs[a]-dd>=xs[1])
			{
				int r=a-1;
				while(xs[b]-xs[r]<=dd)
				{
					r--;
				}
				for(int i=r;i>=1&&xs[a]-xs[i]<=dd;i--)
				{
					cnt++; 
					q.push({i,b,c,d});
				}
			}
			for(int i=a-1;i>=1&&xs[c]-xs[i]<=dd;i--)
			{
				cnt++;
				q.push({i,b,c,d});
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
