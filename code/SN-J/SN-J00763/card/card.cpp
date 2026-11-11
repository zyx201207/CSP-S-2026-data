//SN-J00763 西安交通大学附属中学 胡妍馨 
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000000];
int ans[1000000];
int main(){
	freopen("card6.in","r",stdin);
	freopen("card6.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){ 
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){//第几局游戏
		for(int j=i-1;j<=n;j++){//哪些牌 
			ans[a[j]]++;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
