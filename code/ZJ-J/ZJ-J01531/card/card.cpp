#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500086];
int ans[300086];
stack<int>v[300086];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>0;i--){
		if(!v[a[i]].empty()){
			for(int j=i+1;j<v[a[i]].top();j++){
				if(!v[a[j]].empty())v[a[j]].pop();
			}
		}
		v[a[i]].push(i);
		for(int j=1;j<=m;j++){
			if(!v[j].empty())ans[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}