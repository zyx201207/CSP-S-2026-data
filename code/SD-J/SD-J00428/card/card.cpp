#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#define int long long
//#define const 998244353
using namespace std;
int n,m,a[500010],num[500010],ans[500010];bool head[500010];
vector<int>appear[500010]; 
pair<int,int>pir[500010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		num[a[i]]++;
		appear[a[i]].push_back(i);
		pir[a[i]]=make_pair(i,a[i]);
	}
	sort(pir+1,pir+1+m);
	for(int i=1;i<=m;i++){
//		cout<<"i="<<i<<'\n';
//		cout<<pir[i].first<<' '<<pir[i].second<<'\n';
		head[pir[i].first]=1;
		int t=pir[i].second;
		for(int j=0;j<appear[t].size();j++){
//			cout<<appear[t][j]<<' ';
			if(head[appear[t][j]-1]){
				ans[t]+=ans[a[appear[t][j]-1]];
			}
		}
		ans[t]+=num[t];
//		cout<<"t:"<<ans[t]<<'\n';
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i];
		if(i!=m)cout<<' ';
	}
	return 0;
}
