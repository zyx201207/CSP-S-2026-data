#include <iostream>

using namespace std;
using ll=long long;

const int N=2e5+5;

int n;
struct Node
{
	int a;
	char c;
}a[N];
ll ans;
ll sumlen,l,r;
int maxa;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i].a>>a[i].c;
		sumlen+=a[i].a;
		maxa=max(maxa,a[i].a);
	}
	if(maxa==1)
	{
		for(int i=1,j=n;i<=j;i++,j--)
		{
			if(a[i].c!=a[j].c) ans++;
		}
		cout<<ans;
		return 0;
	}
	ll m=0,mlen=0;
	bool flag=true;
	if(sumlen)
	for(int i=1;i<=n;i++)
	{
		if(mlen+a[i].a==sumlen/2)
		{
			m=i+1;
			mlen+=a[i].a; 
			flag=true;
		}
		if(mlen+a[i].a>sumlen/2)
		{
			m=i;
			flag=false;
		}
	}
	if(!flag)
	{
		ans+=min(sumlen/2-mlen,a[m+1].a-(sumlen/2-mlen));
		a[m].a-=2*ans;
	}
	for(int i=1,j=n;i<=m;)
	{
		if(l+a[i].a>r+a[j].a)
		{
			if(a[i].c==a[j].c)
			{
				ans+=a[j].a;
				r+=a[j].a;
				j--;
				l+=a[j].a;
				a[i].a-=a[j].a;
			}
			else
			{
				r+=a[j].a;
				j--;
				l+=a[j].a;
				a[i].a-=a[j].a;
			}
		} 
		else if(l+a[i].a<r+a[j].a)
		{
			if(a[i].c==a[j].c)
			{
				ans+=a[i].a;
				l+=a[i].a;
				i++;
				r+=a[i].a;
				a[j].a-=a[i].a; 
			}
			else
			{
				l+=a[i].a;
				i++;
				r+=a[i].a;
				a[j].a-=a[i].a; 
			}
		}
		else
		{
			if(a[i].c==a[j].c)
			{
				ans+=a[i].a;
				i++; j--;
				l+=a[i].a; r+=a[j].a;
			}
			else 
			{
				i++; j--;
				l+=a[i].a; r+=a[j].a;
			}
		}
	}
	cout<<sumlen/2-ans;
	return 0;
}
