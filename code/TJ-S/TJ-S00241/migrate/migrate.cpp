#include<bits/stdc++.h>
using namespace std;
long long c,t,n;
long long d;
long long a[100000]={0};
long long ct[8000][8000]={0};
long long w[8000][8000]={0};
long long ans=0;
struct node{
	int m;
	int s;
};
queue <node> q;
void bfs(int i)
{
	while(q.empty()==0)
	{
		node f=q.front();
		for(int j=f.m+1;j<n;j++)
		{
			if(a[j]-a[f.m]<=d)
			{
				if(w[i][j]==0)
				{
					w[i][j]=f.s+1;
					ct[i][j]++;
				}
				else if(w[i][j]==f.s+1)
				{
					ct[i][j]++;
				}
				node r={j,f.s+1};
				q.push(r);
			}
		}
		q.pop();
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for(int T=0;T<t;T++)
	{
		cin >> n >> d;
		for(int i=0;i<n;i++)
		{
			cin >> a[i];
		}
		if(c==11||c==12)
		{
			long long l=a[1]-a[0];
			long long ll=d/l;
			if(ll<=1)
			{
				cout << 0 << "\n";
			}
			else if((n-(ll+ll-1))>=0)
			{
				cout << n-(ll+ll-1) << "\n";
			}
			else 
			{
				cout << 0 << "\n";
			}
		}
		else if(c<11)
		{
			memset(ct,0,sizeof(ct));
			memset(w,0,sizeof(w));
			for(int i=n-2;i>=0;i--)
			{
				node r={i,0};
				q.push(r);
				bfs(i);
			}
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(ct[i][j]==2)
					{
						ans++;
					}
				}
			}
			cout << ans << "\n";
			ans=0;
		}
		else
		{
			cout << "114514 1919810 10086";
		}
	}
	
	
	
	
	
	return 0;
}
