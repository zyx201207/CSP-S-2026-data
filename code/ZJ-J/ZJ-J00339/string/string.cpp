//2
#include<bits/stdc++.h>
using namespace std;
//#define int long long
long long T,a[210000],sum;
char b[210000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	for(long long i=1;i<=T;i++)
		cin>>a[i]>>b[i];
	long long cntl=a[1],cntr=a[T];
	long long l=1,r=T;
	while(l<=r)
	{
		int t=min(cntl,cntr);
		if(b[l]!=b[r]) sum+=t;
		cntl-=t;
		cntr-=t;
		if(cntl<=0)
		{
			l++;
			cntl=a[l];
		}
		if(cntr<=0)
		{
			r--;
			cntr=a[r];
		}
	}
	cout<<sum;
	return 0;
}