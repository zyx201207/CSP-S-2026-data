#include<bits/stdc++.h>
using namespace std;
int a[500005],ans[500005];


bool check(int i,int j,int mb){
	for(int k=i;k<=j;++k){
		if(mb==a[k]){
			return true;
		}
		return false;
	}
}
vector<int> v;
void cl(){
	while(!v.empty()){
		v.pop_back();
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(check(i,j,a[j])) cl();
			else {
				v.push_back(a[i]);
			}
			
		}
		for(int i=0;i<v.size();i++){
			ans[v[i]]+=1;
		}
	}
	for(int i=1;i<=m;++i){
		cout<<ans[i]<<" ";
		cerr<<ans[i]<<" ";
	}
	return 0;
}
