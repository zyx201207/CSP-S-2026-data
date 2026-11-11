#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
vector<pair<long long,char> > v;
vector<pair<long long,char> > v1;
vector<pair<long long,char> > v2;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long sum=0;
	for (int i=1;i<=n;i++)
	{
		int a;
		char c;
		cin>>a>>c;
		v.push_back({a,c});
		sum+=a;
	}
	long long sum1=0;
	long long qian=sum/2;
	bool flag=0;
	for (int i=0;i<n;i++)
	{
		long long a=v[i].first;
		char c=v[i].second;
		sum1+=a;
		if (sum1<=qian)
		{
			v1.push_back({a,c});
		}
		if (sum1>qian)
		{
			if (flag==0)
			{
				long long duo=sum1-qian;
				if (duo!=a) v1.push_back({a-duo,c});
				if (sum%2==0)
				{
				    if (duo!=0) v2.push_back({duo,c});
			    }
			    else
			    {
			    	if (duo>1) v2.push_back({duo-1,c});
				}
				flag=1;
			}
			else v2.push_back({a,c});
		}
	}
	long long cnt=0;
	reverse(v2.begin(),v2.end());
//	for (int i=0;i<v1.size();i++) cout<<v1[i].first<<" "<<v1[i].second<<"\n";
//	cout<<"\n";
//	for (int i=0;i<v2.size();i++) cout<<v2[i].first<<" "<<v2[i].second<<"\n";
    while (!v1.empty())
    {
    	long long a=v1.back().first;
    	char c=v1.back().second;
    	v1.pop_back();
    	while (!v2.empty() && v2.back().first<=a && a>=0LL)
    	{
    		if (v2.back().second!=c) cnt+=v2.back().first;
    		a-=v2.back().first;
    		v2.pop_back();
		}
		if (a!=0)
		{
			if (v2.back().second!=c) cnt+=a;
			v2[(int)v2.size()-1].first-=a;
		}
	}
	cout<<cnt;
	return 0;
}
