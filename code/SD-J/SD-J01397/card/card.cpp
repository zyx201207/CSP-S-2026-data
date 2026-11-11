#include<bits/stdc++.h>
#define ll long long
#define inf 0x7fffffff
using namespace std;
ll n,m,a[500005],dp[300005],lt[500005];
void find(int h){
	for(int i=h;i<=n;i++){
		if(i!=lt[a[i]]){
			i=lt[a[i]]-1;
			continue;
		}
		dp[a[i]]++;
	}
	return ;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=n;i>=1;i--){
		if(lt[a[i]]==0)	lt[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		find(i);
	}
	for(int i=1;i<=m;i++){
		cout<<dp[i]<<" ";
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
