#include<bits/stdc++.h>
using namespace std;
int a[500010],cnt[500010];
vector<int>v;
map<int,int>mp;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--){
		if(!mp[a[i]]){
			v.push_back(a[i]);
			mp[a[i]]=i;
		}
		else{
			int j=v.size()-1;
			while(v[j]!=a[i]){
				j--;
			} 
			while(v.size()-1!=j){
				int z=v[v.size()-1];
				cnt[z]+=mp[z]-i;
				mp[z]=0;
				v.pop_back();
			}
		}
	}
	for(int i=1;i<=m;i++){
		cnt[i]+=mp[i];
		cout<<cnt[i]<<" ";
	}
	return 0;
}

