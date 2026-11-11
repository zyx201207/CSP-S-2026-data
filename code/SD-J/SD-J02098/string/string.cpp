#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
struct node
{
	int l;
	int r;
	int x;
};
node cut[200005];
char c[200005];
int v[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,tot=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>v[i]>>c[i];
		ans+=v[i];
		cut[i].l=cut[i-1].r+1,cut[i].r=cut[i].l+v[i]-1,cut[i].x=c[i]-'a';
	}
	int l=1,t=n;
	int llen=cut[l].r-cut[l].l+1,rlen=1+cut[t].r-cut[t].l;
	while(cut[l].r<=cut[t].l)
	{
		if(cut[l].x!=cut[t].x)
		{
			if(cut[l].r-1>=ans-cut[t].l)
			{
				tot+=rlen;
				llen-=rlen;
			}
			else
			{
				tot+=llen;
				rlen-=llen;
			}
		}
		if(cut[l].r-1<ans-cut[t].l)	
		{
			l++;
			llen=cut[l].r-cut[l].l+1;
		}
		else
		{
			t--;
			rlen=cut[t].r-cut[t].l+1;
		}
	}
	cout<<tot<<endl;
	return 0;
}
