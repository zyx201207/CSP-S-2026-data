#include<bits/stdc++.h>
using namespace std;
int a[500005],n,m,ans[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int t=1;t<=n;t++){
		map<int,int> mp;
		bool flag=0;
		for(int i=t;i<=n;i++){
			if(mp[a[i]]){
				for(int j=mp[a[i]];j<=i;j++){
					mp[a[j]]=0;
				}
			}
			mp[a[i]]=i;
		}
		for(auto s: mp){
			if(s.second!=0) ans[s.first]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" "; 
	return 0;
	//ncgm wcgm djyqcgm , gmgmdgm gmgmxgm , gmgmgmdjq
	 
} 
