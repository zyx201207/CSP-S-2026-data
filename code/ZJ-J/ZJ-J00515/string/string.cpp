#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long n,cnt=0;
	cin>>n;
	vector<pair<long long,char>>a;
	
	for(long long i=1;i<=n;i++)
	{
		pair<long long,char>aa;
		cin>>aa.first>>aa.second;
		a.push_back(aa);
	}
	
	long long l=0,r=n-1;
	while(l<r)
	{
		if(a[l].second!=a[r].second)
		{
			cnt+=min(a[l].first,a[r].first);
		}
		a[l].first-=min(a[l].first,a[r].first);
		a[r].first-=min(a[l].first,a[r].first);
		if(a[l].first==0)
		{
			l++;
		}
		if(a[r].first==0)
		{
			r--;
		}
	}
	cout<<cnt;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
