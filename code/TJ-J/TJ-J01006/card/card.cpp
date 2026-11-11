#include<bits/stdc++.h>
using namespace std;
int a[500009],ans[300009];
vector<int> q;
int find(int a){
	for(int i = 0;i<q.size();i++){
		if(q[i]==a){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	for(int i = 1;i<=n;i++){
		q.clear();
		for(int j = i;j<=n;j++){
			if(find(a[j])){
				while(!q.empty()&&q.back()!=a[j]){
					q.pop_back();
				}
			}
			else{
				q.push_back(a[j]);
			}
		}
		for(int j = 1;j<=m;j++){
			if(find(j)){
				ans[j]++;
			}
		}
	}
	for(int i = 1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
