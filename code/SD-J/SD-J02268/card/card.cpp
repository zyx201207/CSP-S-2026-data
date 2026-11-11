#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	vector<int>s(n+1,0);
	bool flag=true;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		if(s[i]<=s[i-1])
			flag=false;
	}
	if(flag){
		vector<int>ans(n+1,0);
		for(int i=1;i<=n;i++)
			ans[s[i]]=max(ans[s[i]],i);
		for(int i=1;i<=n;i++)
			cout<<ans[i]<<" ";
		cout<<"\n";
		return 0;
	}
	vector<int>ans(n+1,0);
	for(int i=1;i<=n;i++)
	{
		vector<int>a;
		vector<bool>mp(m+1,false);
		for(int j=i;j<=n;j++)
		{
			if(!mp[s[j]]){
				mp[s[j]]=true;a.push_back(s[j]);
			}else{
				int t=0;
				for(int k=0;k<a.size();k++)
				{
					if(a[k]==s[j]){t=k;break;
					}
				}
				int sz=a.size();
				for(int k=1;k<=sz-t;k++)
					mp[a.back()]=false,a.pop_back();
				mp[s[j]]=true;a.push_back(s[j]);
			}
		}
		for(int j=1;j<=m;j++)
			if(mp[j])
				ans[j]++;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}
