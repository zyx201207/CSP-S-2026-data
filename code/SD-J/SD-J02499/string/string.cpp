#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int a;
	char c;
}str[200010];
queue<Node> qian,hou;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	long long sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>str[i].a>>str[i].c;
		sum+=str[i].a;
	}
	long long q=sum/2,h=sum/2;
	for(int i=1;i<=n;i++)
	{
		if(q<=str[i].a)
		{
			qian.push({q,str[i].c});
			break;
		}
		qian.push(str[i]),q-=str[i].a;
	}
	for(int i=n;i>=1;i--)
	{
		if(h<=str[i].a)
		{
			hou.push({h,str[i].c});
			break;
		}
		hou.push(str[i]),h-=str[i].a;
	}
	long long ans=0;
	Node cnt_q={0,' '},cnt_h={0,' '};
	while(!qian.empty() || !hou.empty() || cnt_q.a!=0 || cnt_h.a!=0)
	{
		if(cnt_q.a==0)
		{
			if(!qian.empty())
			{
				cnt_q=qian.front();
				qian.pop();
			}
		}
		if(cnt_h.a==0)
		{
			if(!hou.empty())
			{
				cnt_h=hou.front();
				hou.pop();
			}
		}
		int jian=min(cnt_q.a,cnt_h.a);
		cnt_q.a-=jian,cnt_h.a-=jian;
		if(cnt_q.c!=cnt_h.c) ans+=jian;
	}
	cout<<ans;
	return 0;
}
