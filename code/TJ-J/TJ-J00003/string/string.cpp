//100%
#include<bits/stdc++.h>
using namespace std;
struct
{
	long long x;
	char c;
}a[200005];
int n;
long long ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long i,j;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i].x>>a[i].c;
	int ii=1,ij=n;
	while(ii<ij)
	{
		i=a[ii].x;j=a[ij].x;
		int t=min(j,i);
		if(a[ii].c!=a[ij].c)
			ans+=t;
		a[ii].x-=t;
		a[ij].x-=t;
		if(a[ii].x==0)	ii++;
		if(a[ij].x==0)	ij--;
//		cout<<ii<<" "<<ij<<endl;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
