#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
const ll maxn=5009;
ll c,T;
ll n,d;
ll s[maxn],l[maxn],r[maxn],tmp,tmp2,o;
ll la[maxn];
ll lg[maxn];
void init(ll n)
{
	o=0;
	memset(la,0,sizeof(ll)*(n+5));
}
struct node{
	ll l,r;
}a[maxn];
ll cnt=0;
ll dpl[maxn][maxn],dpr[maxn][maxn];
int main()
{
	fre(migrate);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		init(n);
		cnt=0;
		for(ll i=1;i<=n;i++)
		{
			cin>>s[i];	
			l[i]=1;
			r[i]=n;
			if(s[i]>s[1]+d&&o==0)
			{
				o=i;
			}
		}	
		r[1]=o-1;
		tmp=o;
		for(ll i=2;i<=n;i++)
		{
			while(tmp<=n&&s[i]+d>=s[tmp])
			{
				tmp++;
			}
			r[i]=tmp-1;
			if(tmp==n+1)
			{
				break;
			}
		}
		l[o-1]=1;
		tmp2=1;
		for(ll i=o;i<=n;i++)
		{
			while(s[tmp2]+d<s[i])
			{
				tmp2++;
			}
			l[i]=tmp2;
		}
		ll j=1;
		for(ll i=1;i<=n;i++)
		{
			while(l[j]<=r[i]&&j<=n)
			{
				if(l[j]+1==r[i])
				{
					break;
				}
				j++;
			}
			if(l[j]+1==r[i])
			{
				la[i]=j;
				cnt++;
				a[cnt].l=i;
				a[cnt].r=j;
			}
			if(j==n+1)
			{
				break;
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}