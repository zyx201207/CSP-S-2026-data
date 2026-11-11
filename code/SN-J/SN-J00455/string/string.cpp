#include<bits/stdc++.h>
using namespace std;
//SN-J00455 zhaoweize

int n;
struct node{
	int num;
	char c;
}a[200005];
long long ans=0;
int fp=1,bp;//frontpos,backpos

int main()
{	
	ios::sync_with_stdio(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	bp=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].num>>a[i].c;
	}
	while(fp!=bp&&fp<=bp)
	{	
		if(a[fp].num==a[bp].num)
		{
			if(a[fp].c!=a[bp].c)ans+=a[fp].num;
			fp++,bp--;
		}
		else if(a[fp].num>a[bp].num)
		{
			if(a[fp].c!=a[bp].c)ans+=a[bp].num;
			a[fp].num-=a[bp].num;
			bp--;	
		}
		else if(a[fp].num<a[bp].num)
		{
			if(a[fp].c!=a[bp].c)ans+=a[fp].num;
			a[bp].num-=a[fp].num;
			fp++;
		}
	}
	cout<<ans;
	return 0;
}
