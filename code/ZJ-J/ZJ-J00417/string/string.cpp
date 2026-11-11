#include <bits/stdc++.h>
using namespace std;
pair<long long,char> a[200010];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0;
	string s;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		long long x;
		char y;
		cin>>x>>y;
		a[i]={x,y};
	}
	long long ll=1,rr=n;
	while(ll<rr)
	{
		if(a[ll].second!=a[rr].second){
			sum+=min(a[ll].first,a[rr].first);
		}
		if(a[ll].first>a[rr].first) a[ll].first-=a[rr].first,rr--;
		else if(a[ll].first<a[rr].first) a[rr].first-=a[ll].first,ll++;
		else ll++,rr--;
	}
	cout<<sum;
	return 0;
}
