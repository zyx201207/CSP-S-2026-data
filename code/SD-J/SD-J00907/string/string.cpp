#include <bits/stdc++.h>
#define CHECK_SIZE(x) cout<<#x<<": "<<sizeof(x)%1024<<"B "<<sizeof(x)%(1024*1024)/1024<<"KB "<<sizeof(x)/1024/1024<<"MB\n"
using namespace std;
using ll = long long;
const int N=2e5+7;
int n;
struct node
{
	int c;
	char ch;
}a[N],b[N];
void check_size()
{
	CHECK_SIZE(a);
	CHECK_SIZE(b);
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
//	check_size();
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].c>>a[i].ch;
		b[n-i+1]=a[i];
	}
	
	ll sum1=1,sum2=1;
	ll ans=0;
	for(int i=1,j=1;i<=n;i++)
	{
		while(j<=n && sum1+a[i].c>=sum2)
		{
			if(sum1+a[i].c>=sum2)
				if(a[i].ch!=b[j].ch)
					ans+=min(sum1+a[i].c-1,sum2+b[j].c-1)-
						 max(sum1,sum2)+1;
			if(sum1+a[i].c>sum2+b[j].c)
				sum2+=b[j++].c;
			else
				break;
		}
		sum1+=a[i].c;
	}
	cout<<ans/2;
	return 0;
} 
