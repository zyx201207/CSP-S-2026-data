#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;
string a,b,c,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	bool ans=1;
	for(int i=0;i<2;i++)if(a[i]!=c[i])ans=0;
	if(ans)
	{
		cout<<1;
		ll i,l=0,r=0;
		for(i=0;i<2;i++)
		{
			l+=int(b[i]);
			r+=int(d[i]);
		}
		if(l==r)
		{
			cout<<1;
			char x,y;
			bool vis=1;
			x=b[2];
			y=d[2];
			if((x=='C'&&y=='D')||(y=='C'&&x=='D'))vis=0;
			if(vis)
			{
				cout<<1;
				bool cnt=0;
				ll w=int(x),m=int(y);
				if(w+1==m)cnt=1;
				else if(m+1==w)cnt=1;
				if(cnt)cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
