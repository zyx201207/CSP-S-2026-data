#include <bits/stdc++.h>
using namespace std;
struct node
{
	long long len;
	char x;
};
node a[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].len>>a[i].x;
	long long ans=0;
	int i=0,j=n;
	while(i<j)
	{
		long long leni=a[i].len,lenj=a[j].len;
		long long minl=min(leni,lenj);
		if(a[i].x!=a[j].x) ans+=minl;
		if(lenj>leni)
		{
			i++;
			a[j].len-=minl;
		}
		else if(lenj<leni)
		{
			j--;
			a[i].len-=minl;
		}
		else
		{
			i++;
			j--;
		}
	}
	cout<<ans;
	return 0;
}
