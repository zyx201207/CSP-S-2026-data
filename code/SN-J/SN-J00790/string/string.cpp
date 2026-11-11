//高一轩 SN-J00790 交大附中 
#include<bits/stdc++.h>
using namespace std;
int n;
struct note
{
	long long x;
	char c;
}a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		int sa;
		char cc;
		cin>>sa>>cc;
		a[i].x=sa;
		a[i].c=cc;
		sum+=sa;
	}
	long long ans=0;
	long long qs=sum/2,hs=sum/2,qi=1,hi=n;
	while(qs!=0&&hs!=0)
	{
		if(qs==0&&hs==0) break;
		else if(qi==hi) break;
		if(a[qi].x>=a[hi].x)
		{
			qs-=a[hi].x;
			hs-=a[hi].x;
			if(a[qi].c!=a[hi].c)
			{
				ans+=a[hi].x;
			}
			a[qi].x-=a[hi].x;
			a[hi].x=0;
			hi--;
		}
		else
		{
			qs-=a[qi].x;
			hs-=a[qi].x;
			if(a[qi].c!=a[hi].c)
			{
				ans+=a[qi].x;
			}
			a[hi].x-=a[qi].x;
			a[qi].x=0;
			qi++;
		}
	}
	cout<<ans;
	return 0;
} 
