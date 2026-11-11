// 欧阳宁佑 SN-J00845 西安市铁一中学 
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,now,cnt,len;
pair<int,char>in[200010];
int qian[200010];
vector<pair<int,char>>fg;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>in[i].first>>in[i].second;
		qian[i]=qian[i-1]+in[i].first;
		len+=in[i].first;
	}
	for(int i=1;i<=n;i++)
	{
		now+=in[i].first;
		fg.push_back({now,0});
		if(i!=n)fg.push_back({len-now,0});
	}
	sort(fg.begin(),fg.end());
	fg.erase(unique(fg.begin(),fg.end()),fg.end());
	now=1;
	for(auto &p:fg)
	{
		p.second=in[now].second;
		if(p.first==qian[now]) now++;
	}
	for(int i=0;i<(int)fg.size();i++)
	{
		if(fg[i].second==fg[fg.size()-i-1].second) continue;
		if(i==0) cnt+=fg[i].first;
		else cnt+=fg[i].first-fg[i-1].first;
	}
	cout<<cnt/2;
	return 0;
}
