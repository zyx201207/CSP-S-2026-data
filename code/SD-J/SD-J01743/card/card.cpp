#include<bits/stdc++.h>
using namespace std;//É¾µôfreopenµÄ×¢ÊÍ£¡£¡£¡ 
long long n,cnt,m,n1;
bool b[500010];
long long a[500010];
long long c[500010];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	n1=n;
	while(n1--)
	{
		stack<int> q;
		for(int i=n-n1;i<=n;i++)
	 {
		if(b[a[i]]==0)
		{
			b[a[i]]=1;
			q.push(a[i]);
		}
		else
		{
			while(!q.empty()&&q.top()!=a[i])
			{
				b[a[i]]=0;
				q.pop();
			}
			b[a[i]]=1;	
		}
		
	 }
	 for(int i=1;i<=m;i++)
	 {
	 	if(b[i]==1)
	 	c[i]++;
	 }
	 for(int i=1;i<=m;i++)
	 b[i]=0;
	}
	
    for(int i=1;i<=m;i++)
    cout<<c[i]<<" ";
	return 0;

}
