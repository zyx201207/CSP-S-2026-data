#include<bits/stdc++.h>
using namespace std;

long long int c,n,m,d,q,w[500005],k,x,y,i,j,l,flag1,flag2,ans;

struct node
{
	long long int a,t;
}s[1000005];

bool cmp(node e,node f)
{
	return e.a < f.a;
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(i = 1;i <= m;i++) cin >> w[i];
	for(i = 1;i <= n;i++)
	{
		cin >> k;
		for(j = 1;j <= k;j++)
		{
			l++;
			cin >> s[l].a >> s[l].t;
		}
	}
	sort(s+1,s+1+l,cmp);
	for(i = 1;i <= q;i++)
	{
		cin >> x >> y;
		flag1 = 0,flag2 = 0;
		ans = 0;
		for(j = 1;j <= l;j++)
		{
			if(s[j].a == x)
			{
				flag1 = j;
				ans += w[s[j].a];
			}
			if(s[j].a == y)
			{
				flag2 = j;
				ans += w[s[j].a];
				break;
			}
		}
		for(j = flag1;j <= flag2;j++) ans += s[j].t;
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
