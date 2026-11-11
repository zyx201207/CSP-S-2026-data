#include<bits/stdc++.h>
using namespace std;
struct node
{
	int a;
	char c;
}p[200005];
int n;
bool flag=1;
char nz='A';
unsigned long long z=0,nowz;
unsigned long long ans=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>p[i].a>>p[i].c;
    	if(nz=='A') nz=p[i].c;
    	else if(nz!=p[i].c) flag=0;
    	z+=p[i].a;
	}
	if(flag==1)
	{
		cout<<0;
		return 0;
	}
	int k;
	short int pd;
	for(int i=1;i<=n;i++)
    {
    	if((nowz+p[i].a)>=ceil(z/2.0))
    	{
    		if((nowz+1)<ceil(z/2.0)){;if((nowz+p[i].a)>ceil(z/2.0))pd=0;if((nowz+p[i].a)==ceil(z/2.0))pd=2;}
    		else if((nowz+1)==ceil(z/2.0))pd=1;
			k=i;
    		break;
		}
		nowz+=p[i].a;
	}
	if(z%2==0)
	{
		if(pd==2){
			p[k].a--;
			p[k+1].a--;
			ans++;
		}
		else if(pd==1)
		{
			p[k].a-=2;
		}
		else
			p[k].a-=2;
	}
	else {
		if(pd==2)
		{
			p[k].a--;
		}
		else if(pd==1)
		{
			p[k].a--;
		}
		else 
		{
			p[k].a-=3;
		}
	}
	int l=1,r=n;
	while(l<r)
	{
		int nowq=abs(p[l].a-p[r].a);
		if(nowq==0)
		{
			if(p[l].c!=p[r].a)
			{
				ans+=p[l].a;
			}
		}
		else
		{
			ans+=nowq;
			if(p[l].a>p[r].a)
			{
				p[r-1].a-=nowq;
			}
			else
			{
				p[l+1].a-=nowq;
			}
			if(p[l].c!=p[r].c)
				ans+=min(p[l].a,p[r].a);
		}
		r--;
		l++;
	}
	cout<<ans;
    return 0;
}
