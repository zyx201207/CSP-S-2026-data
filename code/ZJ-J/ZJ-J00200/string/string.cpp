#include<bits/stdc++.h>
using namespace std;
#define LL long long 
const int N=2e5+10;
char ch[N];
LL a[N];
LL n;
LL len=0;
LL sum[N];
LL ans;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(LL i=1;i<=n;i++)
	{
		cin>>a[i]>>ch[i];
		len+=a[i];
		sum[i]=sum[i-1]+a[i];
	}
	LL i=1,j=n,l=0,r=len;
	while(i<j)
	{
		LL x=sum[i]-l;
		LL y=r-sum[j-1];
		if(ch[i]!=ch[j])ans+=min(x,y);
		if(x<y)
		{
			l+=x;
			r-=x;
			i++;
		}
		else if(x>y)
		{
			l+=y;
			r-=y;
			j--;
		}
		else
		{
			l+=x;
			r-=x;
			j--;
			i++;
		}
	}
	cout<<ans;
}
