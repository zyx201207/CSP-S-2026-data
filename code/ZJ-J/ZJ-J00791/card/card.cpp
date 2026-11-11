#include <bits/stdc++.h>
using namespace std;
int a[1000010];
int ca[1000010];
int ct[1000010];
int ans[1000010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int f = 0;
	for(int i = 1;i<=n;i++){
		cin>>a[i];	
		if(a[i]<a[i-1])f = 1;
	}
	if(f == 0){
		for(int i = 2;i<=n+1;i++){
			if(a[i] != a[i-1]||i == n+1){
				cout<<i-1<<" ";
			}
		}
		return 0;
	}
	for(int i = n;i>=1;i--){
		if(ca[a[i]] == 0){
			ca[a[i]] = i;		
		}else{
			ct[i] = ca[a[i]];
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = i;j<=n;j++){
			ans[a[j]]++;
			if(ct[j]!=0){
				j = ct[j];
			}
		}
	}
	for(int i = 1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}