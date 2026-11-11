#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,pos,pos2;
long long ans;
vector<pair<long long,char>> v,vv;
vector<long long> zhui;
bool flag;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	vv.resize(n+1);
	zhui.resize(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>vv[i].first>>vv[i].second;
		zhui[i]=zhui[i-1]+vv[i].first;
	}
	for(int i=1;i<=n;i++)
	{
		if((zhui[n]+1)/2<=zhui[i] && !flag)
		{
			flag=true;
			if(zhui[n]&1)
			{
				if(zhui[i]==(zhui[n]+1)/2)
				{
					v.push_back(make_pair(vv[i].first-1,vv[i].second));
					v.push_back(make_pair(1,vv[i].second));
					pos=v.size()-2;
					pos2=v.size();
				}
				else
				{
					v.push_back(make_pair(((zhui[n]+1)/2)-zhui[i-1]-1,vv[i].second));
					v.push_back(make_pair(1,vv[i].second));
					v.push_back(make_pair(zhui[i]-((zhui[n]+1)/2),vv[i].second));
					pos=v.size()-3;
					pos2=v.size()-1;
				}
			}
			else
			{
				if(zhui[i]>zhui[n]/2)
				{
					v.push_back(make_pair((zhui[n]/2)-zhui[i-1],vv[i].second));
					v.push_back(make_pair(zhui[i]-(zhui[n]/2),vv[i].second));
					pos=v.size()-2;
					pos2=v.size()-1;
				}
				else
				{
					v.push_back(vv[i]);
					pos=v.size()-1;
					pos2=v.size();
				}
			}
		}
		else v.push_back(vv[i]);
	}
	while(pos!=-1 && pos2!=v.size())
	{
		int u=min(v[pos].first,v[pos2].first);
		v[pos].first-=u;
		v[pos2].first-=u;
		if(v[pos].second!=v[pos2].second) ans+=u;
		if(v[pos].first==0) pos--;
		if(v[pos2].first==0) pos2++;
	}
	cout<<ans;
	return 0;
}
