#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[300010];
bool f=true;
map<int,int>mp;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])f=false;
	}
	if(f){	
		for(int i=1;i<=n;i++){
			mp[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			cout<<mp[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		vector<int>ve;
		for(int i=1;i<=m;i++)mp[i]=0;
		for(int j=i;j<=n;j++){
			if(mp[a[j]]){
				for(int p=mp[a[j]]-i;p<ve.size();p++)mp[ve[p]]=0;
				ve.erase(ve.begin()+j-i,ve.end());
				ve.push_back(a[j]);
				mp[a[j]]=j;
			}
			else{
				ve.push_back(a[j]);
				mp[a[j]]=j;
			}
		}
		for(int j=1;j<=m;j++){
			if(mp[j])ans[j]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
