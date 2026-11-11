#include<bits/stdc++.h>
using namespace std;
const int N=500050;
long long int n,m,a[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int sum=0,cnt[N];
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	int max=-999;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j>=0;j--)
		{
			sum+=a[i]-a[j];
			if(sum>m) continue;
			cnt[i]++;
		}
		if(max<cnt[i])
			max=cnt[i];
		sum=0;
	}
	printf("%d",max);
	return 0;
}