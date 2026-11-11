#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
int n;
struct node{
	long long a;
	char c;
}q[N];
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>q[i].a>>q[i].c;
	}
	int head=1,tail=n;
	while(head<tail)
	{
		long long minn=min(q[head].a,q[tail].a);
		if(q[head].c!=q[tail].c)
			ans+=minn;
		if(q[head].a==q[tail].a)
		{
			head++;
			tail--;
		}
		else if(q[head].a<q[tail].a)
		{
			head++;
			q[tail].a-=minn;
		}
		else
		{
			tail--;
			q[head].a-=minn;
		}
	}
	cout<<ans;
	return 0;
}

