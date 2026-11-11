#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
const int N=2e5+10;
int n,m,a[N];
int ans=0;
vector<int>cnt[35],sum[N];
bool cmp(int a,int b){
	return a>b;
}
map<int,int>mp;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		mp[a[i]]++;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;++i){
		for(int j=1;1<<j<=a[i];++j){
			if(a[i]&(1<<j)==1){
				cnt[j].push_back(a[i]);
				if(a[i]!=a[i-1])sum[a[i]].push_back(j);
			}
		}
	}
	for(int i=1;i<=n-m+1;++i){
		int nowm=m;
		for(int j=sum[a[i]].size()-1;j>=0;--j){
			if(cnt[sum[a[i]][j]].size()>1){
				for(int k=1;k<cnt[sum[a[i]][j]].size();++j){
					if(cnt[sum[a[i]][j]][k]==a[i]&&map[a[i]]==1) continue;
					
				}
			}
		}
	}
	return 0;
}
