#include<bits/stdc++.h>
using namespace std;

char inc;

int ini32x;

bool signf;

inline int _sri32()
{
	inc=getchar();
	if(inc=='-')
	{
		signf=true;
		inc=getchar();
	}
	else signf=false;
	ini32x=0;
	while(isdigit(inc))
	{
		ini32x=(ini32x<<3)+(ini32x<<1)+(inc^0x30);
		inc=getchar();
	}
	return signf?-ini32x:ini32x;
}

inline void _swui32(unsigned int x)
{
	if(x>9u)_swui32(x/10u);
	putchar((x%10u)^0x30);
}

inline void _swi32(int x)
{
	(x<0)?putchar('-'),_swui32(-x):_swui32(x);
}

int c,n,m,d,q,w[500005],k[505],s,e;

struct node
{
	int id,t;
	void read()
	{
		id=_sri32();
		t=_sri32();
	}
}x,y;

vector<node>a[505];

vector<node>z[500005];

long long ans;

void solve(int s,int e)
{
	0;
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	c=_sri32();
	n=_sri32();
	m=_sri32();
	d=_sri32();
	q=_sri32();
	
	for(int i=1;i<=m;++i)w[i]=_sri32();
	
	for(int i=1;i<=n;++i)
	{
		k[i]=_sri32();
		for(int j=0;j<k[i];++j)
		{
			x.read();
			y.id=i;
			y.t=x.t;
			a[i].push_back(x);
			z[x.id].push_back(y);
		}
	}
	
	while(q--)
	{
		s=_sri32();
		e=_sri32();
		solve(s,e);
	}
	
	fclose(stdout);
	return 0;
}

