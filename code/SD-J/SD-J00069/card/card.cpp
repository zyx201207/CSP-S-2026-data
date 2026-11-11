#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>v[10009];
int arr[500009];
int ans[300009];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		v[arr[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;){
			int l=v[arr[j]].size()-1;
			if(v[arr[j]][l]<=j){
				ans[arr[j]]++;
				j++;
				continue;
			}
			j=v[arr[j]][l];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
