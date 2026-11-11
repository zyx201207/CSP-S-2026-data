//SN-S00494+崔雅欣+西安铁一中滨河高级中学 
#include<bits/stdc++.h>
using namespace std;
int n,ma,num;
long long m,a[500005],sum;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++) cout<<a[i]<<" "<<'\n';
	for(int i=1;i<=n;i++)
	{
		num=1;
		sum=0;
		for(int j=i+1;j<=n;j++)
		{
			if(sum>m) break;
			sum=sum+num*(a[j]-a[j-i]);
			num++;
		}
		num-=1;
		ma=max(num,ma);
		if(n-i<=ma) break; 
	 } 
	 cout<<ma;
	return 0;
}
