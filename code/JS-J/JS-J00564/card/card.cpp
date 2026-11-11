#include <bits/stdc++.h>
using namespace std;
vector<int> e[300005];
int n,m,flag,a[500005],num[300005],lxt[300005],last[500005],ans[300005];
int main(){
	//RP++
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		last[lxt[a[i]]] = i;
		lxt[a[i]] = i;
		num[a[i]]++;
		if(a[i-1] > a[i]){
			flag = 1;
		}
	}
	if(!flag){
		int number = 0;
		for(int i = n;i>=1;i--){
			ans[a[i]]++;
		}
		for(int i = 1;i<=m;i++){
			ans[i] = ans[i] + ans[i-1];
			cout<<ans[i]<<" ";
		}
		reutrn 0;
	}
	for(int i = n;i>=1;i--){
		if(!last[i]){
			for(auto v:e[a[i+1]]){
				e[a[i]].push_back(v);
			}
			e[a[i]].push_back(a[i]);
		}
	}
	for(int i = 1;i<=m;i++){
		for(auto v:e[i]){
			ans[v] += num[i];
		}
	}
	for(int i = 1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}