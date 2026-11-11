#include<bits/stdc++.h>
using namespace std;
int a[500010],l[300010];
int ans[300010];
int n,m;
void game(int k){
	int dp[500010];
	int id[300010];
	for(int i=k;i<=n;i++){
		if(id[a[i]]!=0)
		id[a[i]]=i;
		dp[i]=a[i];
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	while(n>0){
		game(n);
		n--;
	}
	return 0;
}
