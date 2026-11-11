//孙正轩  陕西省西安中学  SN-S00323 
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,ans=0;
long long m,num,ji_zhun;
long long a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int l=1,r=1;
	long long lnum=0;
	ji_zhun=a[1];
	while(1)
	{
		r++;
		if(r>n) break;
		num+=(a[r]-ji_zhun)*(r-l);
		ji_zhun=a[r];
		while(num>m&&l<r)
		{
			num-=ji_zhun-a[l];
			l++;
		}
		if(num<=m) ans=max(ans,r-l+1);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
