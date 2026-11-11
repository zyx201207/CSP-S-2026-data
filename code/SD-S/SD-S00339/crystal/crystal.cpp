#include<bits/stdc++.h>
using namespace std;
priority_queue<long long,vector<long long>,greater<long long>> q;
int n;
long long m;
long long ans;
long long plsW[500005];
long long now;
long long num;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		q.push(x);
	}
	now=q.top();q.pop();
	num=1;
	long long l=1;
	while(!q.empty())
	{
		long long cnt=q.top();q.pop();
		long long cha=(cnt-now)*num;
		while(l<=num)
		{
			if(m>=cha)
			{
				m-=cha;
				plsW[num]=cha;
				break;	
			}
			if(l==num)
			{
				l=num+1;
				break;
			}
			m+=plsW[l]*l;
			cha-=(cnt-now);
			l++;
		}
		num++;
		now=cnt;
		ans=max(ans,num-l+1);
	}
	cout<<ans<<endl;
	return 0;
 } 
