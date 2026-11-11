#include<bits/stdc++.h>
using namespace std;const int N=2e5+5;
int a[N],n,m,ans;vector<int>v,v1;
int main(){freopen("and.in","r",stdin);freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i],v.push_back(a[i]);
	for(int i=20;i>=0;i--){
		int cnt=0;
		for(int j=0;j<v.size();j++)
			if(v[j]&(1<<i))
				cnt++;
		if(cnt<m)continue;
		ans+=(1<<i);
		for(int j=0;j<v.size();j++)
			if(v[j]&(1<<i))v1.push_back(v[j]);
		while(v.size())v.pop_back();
		for(int j=0;j<v1.size();j++)
			v.push_back(v1[j]);
		while(v1.size())v1.pop_back();
	}cout<<ans;
	return 0;
}
