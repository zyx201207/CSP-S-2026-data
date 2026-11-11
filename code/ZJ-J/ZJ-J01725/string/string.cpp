#include<bits/stdc++.h>
using namespace std;
struct Area{
	long long num;
	char c;
	long long l,r;
};
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,m=0,cnt=0;
	cin>>n;
	string s;
	vector<Area> vt(n+1);
	vt[0].r=0;
	for(long long i=1;i<=n;i++)
	{
		cin>>vt[i].num>>vt[i].c;
		vt[i].l=m+1;
		m+=vt[i].num;
		vt[i].r=m;
	}
	long long mid=m/2,ai1=1,ai2=n;
	for(long long i=1;i<=mid;i++)
	{
		if(i>vt[ai1].r)
		{
			ai1++;
		}
		long long i2=m-i+1;
		if(i2<vt[ai2].l)
		{
			ai2--;
		}
		if(vt[ai1].c!=vt[ai2].c)
		{
			cnt++;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
