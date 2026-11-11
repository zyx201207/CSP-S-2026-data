#include<iostream>
#define ll long long
using namespace std;
const int N=2e5+5;
int n;
ll cnt;
int a[N];
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	int l=1,r=n;
	int cntl=a[1],cntr=a[n];
	while(l<r)
	{
		if(c[l]==c[r])
		{
			if(cntl<=cntr)
			{
				cntr-=cntl;
				cntl=0;
			}
			else
			{
				cntl-=cntr;
				cntr=0;
			}
		}
		else
		{
			if(cntl<=cntr)
			{
				cnt+=cntl;
				cntr-=cntl;
				cntl=0;
			}
			else
			{
				cnt+=cntr;
				cntl-=cntr;
				cntr=0;
			}
		}
		if(cntl==0)
		{
			l++;
			cntl=a[l];
		}
		if(cntr==0)
		{
			r--;
			cntr=a[r];
		}
	}
	cout<<cnt;
	return 0;
}
