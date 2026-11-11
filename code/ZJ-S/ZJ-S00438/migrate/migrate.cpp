#include<bits/stdc++.h>
using namespace std;
int cc,t,n,d,a[1000001];
bool bfs(int s,int t)
{
	queue<int>q;
	queue<int>ans;
	q.push(s);
	ans.push(0);
	bool vis[1000001]={};
	int opt=0x3f3f3f3f,cnt=0;
	vis[s]=1;
	while(!q.empty())
	{
		int now=q.front();
		if(ans.front()>opt)break;
		if(now==t)cnt++,opt=ans.front();
		q.pop();
		for(int i=now+1;i<=n;i++)
		{
			if(a[i]-a[now]>d)break;
			q.push(i);
			vis[i]=1;
			ans.push(ans.front()+1);
		}
		ans.pop();
	}
	return cnt==2;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>cc>>t;
	if(cc==11||cc==12)
	{
		while(t--)
		{
			cin>>n>>d;
			int ans=0;
			for(int i=1;i<=n;i++)cin>>a[i];
			int gc=a[2]-a[1];
			int chu=d/gc;
			if(chu==0)cout<<0<<endl;
			cout<<a-(2*d-1);
		}
	}
	while(t--)
	{
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans+=bfs(i,j);
			}
		}
		bfs(1,4);
		cout<<ans<<endl;
	}
	return 0;
}
//CCF quan qian quan feng le
//shen me ni tian ti mu
//gen bing dao ren yi yang
//zhi xiao de quan qian
//jin nian yi jiu zuo zui hao de xin ao
//zai zhe yang xia qu wu da jing sai jiu yao shao yi men le qwq