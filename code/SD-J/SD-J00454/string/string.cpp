#include<bits/stdc++.h>
using namespace std;
struct node{
	int num;char c;
};
node s[200005];
queue<node> p,q;
long long sum,j=1,num,nown,cntn,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].num>>s[i].c;
		sum+=s[i].num;
	}
	
	while(1)
	{
		num+=s[j].num;
		if(num<sum/2)
		{
			q.push({s[j].num,s[j].c});	
		}
		else if(num==sum/2)
		{
			q.push({s[j].num,s[j].c});
			j++;
			break;
		}
		else
		{
			q.push({s[j].num-(num-sum/2),s[j].c});
			s[j].num=num-sum/2;
			break;
		}
		j++;
	}
	if(sum%2!=0)
	{
		s[j].num--;
		if(s[j].num==0)
		{
			j++;
		}
	}
	for(int i=n;i>=j;i--)
	{
		p.push({s[i].num,s[i].c});
	}
	
	cntn=q.front().num;
	char cntc=q.front().c;q.pop();
	char nowc;
	int pd=-1;
	while(!q.empty()||(!p.empty()))
	{
		if(pd==-1)
		{
			nown=p.front().num;
			nowc=p.front().c;
			p.pop();
		}
		else
		{
			nown=q.front().num;
			nowc=q.front().c;
			q.pop();
		}
		if(nowc!=cntc)
		{
			ans+=min(nown,cntn);
		 } 
		if(nown>cntn)
		{
			cntn=nown-cntn;
			cntc=nowc;
			pd=-1*pd;
		}
		else
		{
			cntn-=nown;
		}
	}
	cout<<ans<<endl;
	return 0;
 } 
