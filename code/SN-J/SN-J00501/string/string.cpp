//long long
#include<bits/stdc++.h>
using namespace std;
const int K=2e5+10;
pair<int,char>a[K];
int n;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
	int cntl=1,cntr=n;
	long long ans=0;
	while(cntl<cntr)
	{
		if(a[cntl].first>a[cntr].first)
		{
			a[cntl].first=a[cntl].first-a[cntr].first;
			if(a[cntl].second!=a[cntr].second) ans=ans+a[cntr].first;
			cntr--;
		}
		else
		{
			a[cntr].first=a[cntr].first-a[cntl].first;
			if(a[cntl].second!=a[cntr].second) ans=ans+a[cntl].first;
			cntl++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
