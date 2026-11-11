#include<bits/stdc++.h>
using namespace std;
struct point
{
	long long st,ed;
	char ch;
};
long long n,l,ans,tg;
point p[200001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long a;
		char c;
		cin>>a>>c;
		l+=a;
		p[i].st=p[i-1].ed+1;
		p[i].ed=p[i-1].ed+a;
		p[i].ch=c;
		if(p[i].ch==p[i-1].ch)
		{
			p[i-1].ed=p[i].ed;
			i--,n--;
		}
	}
	if(n==1)
	{
		cout<<0<<endl;
		return 0;
	}
	if(l%2==0)
	{
		for(int i=1;i<=n;i++)
			if(p[i].st<=l/2&&p[i].ed>=l/2)
			{
				tg=i;
				break;
			}
	}
	else
	{
		for(int i=1;i<=n;i++)
			if(p[i].st<=l/2&&p[i].ed>=l/2+1||p[i].st<=l/2+1&&p[i].ed>=l/2+2)
				{
					tg=i;
					break;
				}
	}
	for(int i=tg+1;i<=n;i++)
	{
		long long t=p[i].st;
		p[i].st=l-p[i].ed+1;
		p[i].ed=l-t+1;
	}
	int p_1=1,p_2=n,lst=1,led=min(p[n].ed,p[1].ed);
	while(p_1<tg&&p_2>=tg+1)
	{
		if(p[p_1].ch!=p[p_2].ch)ans+=led-lst+1;
		lst=min(p[p_1].ed,p[p_2].ed);
		if(p[p_1].ed>p[p_2].ed)led=min(p[p_1].ed,p[--p_2].ed);
		else if(p[p_1].ed<p[p_2].ed)led=min(p[++p_1].ed,p[p_2].ed);
		else led=min(p[++p_1].ed,p[--p_2].ed);
	}
	if(p_2==tg)p_2++;
	if(p_1==tg)p_1--;
	if(p[p_2].ed>p[p_1].ed)
	{
		if(p[p_2].ch!=p[tg].ch)ans+=p[p_2].ed-led+1;
	}
	else if(p[p_2].ed<p[p_1].ed)
	{
		if(p[p_1].ch!=p[tg].ch)ans+=p[p_1].ed-led+1;
	}
	cout<<ans<<endl;
	return 0;
}