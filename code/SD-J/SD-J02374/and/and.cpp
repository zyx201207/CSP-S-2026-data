//#include<bits/stdc++.h>
//using namespace std;
//int main()
//{
//	
//	freopen("and5.in","r",stdin);
//	freopen("and5.ans","w",stdout);
//	long long a,s;
//	cin>>a>>s;
//	long long d[a+10];
//	for(int i=1;i<=a;i++)
//	{
//		cin>>d[i];
//	}
//	sort(d+1,d+a+1,greater<int>());
//	long long ans=d[1],l=d[2];//ans&=l;
//	for(int i=2;i<=s;i++)
//	{
//		cout<<ans<<" "<<d[i]<<endl;
//		ans&=d[i];
//	}
////ans&=d[2];
//	cout<<ans<<" "<<d[2];
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;

const int N=2*1e5;
	long long a,x;
	int s[N];
	long long maxn=-1;
	int vis[N];
	
void q(int u,int n)
{
	if(n==x)
	{
		maxn=max(u,maxn);
		return ;
	}
	
	for(int i=1;i<=a;i++)
	{
		if(!vis[i])
		{
			int l=s[i];
			l&=u;
			vis[i]=1;
			q(l,n+1);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	memset(vis,0,sizeof vis);
	cin>>a>>x;
	for(int i=1;i<=a;i++)
	{
		cin>>s[i];
	}
	for(int i=1;i<=a;i++)
	{
		vis[i]=1;
		q(s[i],1);
	}
	cout<<maxn;
	return 0;
}
