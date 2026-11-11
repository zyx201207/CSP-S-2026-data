#include<bits/stdc++.h>
using namespace std;

#define int long long
int n,ans,cnt;
queue<pair<int,char> >q1;
stack<pair<int,char> >q2;

signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		char c;
		cin>>a>>c;
		cnt+=a;
		q1.push(make_pair(a,c));
		q2.push(make_pair(a,c));
	}
	int front=q1.front().first,back=q2.top().first;
	char c1=q1.front().second,c2=q2.top().second;
	int sum1=q1.front().first,sum2=q2.top().first;
	q1.pop(),q2.pop();
//	cout<<cnt<<' '<<cnt/2<<'\n';
	while(front<=(cnt+1)/2||back<=(cnt+1)/2)
	{
//		cout<<front<<' '<<back<<' '<<sum1<<' '<<sum2<<' '<<c1<<' '<<c2<<'\n';
		if(c1!=c2)
		{
			ans+=min(sum1,sum2);
		}
		if(sum1>=sum2)
		{
			sum1-=sum2;
			sum2=0;
		}
		else
		{
			sum2-=sum1;
			sum1=0;
		}
		if(sum1==0)
		{
			front+=q1.front().first;
			sum1=q1.front().first;
			c1=q1.front().second;
			q1.pop();
		}
		if(sum2==0)
		{
			back+=q2.top().first;
			sum2=q2.top().first;
			c2=q2.top().second;
			q2.pop();
		}
	}
	cout<<ans;
	return 0;
}
