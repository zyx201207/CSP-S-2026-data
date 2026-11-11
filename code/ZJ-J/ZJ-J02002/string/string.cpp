#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a;
char c;
vector< pair<ll,char> >v;
ll cnt=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	ll hasdo=0;
	for(int i=0;i<n;i++)
	{
		cin>>a>>c;
		v.push_back({a,c});
	}
	int i=0,j=(int)v.size()-1;
	while(i<j)
	{
		if(v[i].second==v[j].second)
		{
			if(v[i].first>v[j].first)
			{
				v[i].first-=v[j].first;
				j--;
			}else if(v[i].first==v[j].first)
			{
				i++;j--;
			}else
			{
				v[j].first-=v[i].first;
				i++;
			}
		}else
		{
			if(v[i].first>v[j].first)
			{
				cnt+=v[j].first;
				v[i].first-=v[j].first;
				j--;
			}else if(v[i].first==v[j].first)
			{
				cnt+=v[i].first;
				i++;j--;
			}else
			{
				cnt+=v[i].first;
				v[j].first-=v[i].first;
				i++;
			}
		}
	}
	cout<<cnt<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}