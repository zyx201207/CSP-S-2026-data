#include<bits/stdc++.h>
using namespace std;
int cnt[333333];
int n,m;
int a[537537];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		vector<int> path;
		unordered_map<int,bool> mp;
		for(int j=i;j<=n;j++){
			if(mp[a[j]]){
				while(path.back()!=a[j]){
					mp[path.back()]=false;
					path.pop_back();
				}
				path.pop_back();
			}
			else{
				mp[a[j]]=true;
			}
			path.push_back(a[j]);
		}
		for(auto x:path){
			cnt[x]++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",cnt[i]);
	}
	return 0;
}
