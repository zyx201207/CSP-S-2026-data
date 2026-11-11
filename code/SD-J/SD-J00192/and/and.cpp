#include<bits/stdc++.h>
using namespace std;
int ans,a[200005];
int n,m;
void zhao(int p,int kk,int sum,int y){
	if(kk==0){
		ans=max(ans,sum);
		return ;
	}
	if(n<kk){
		return ;
	}
	for(int i=y+1;i<=n;i++){
		zhao(p+1,kk-1,(sum & a[i]),i);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	zhao(1,m,2147483647,0);
	cout << ans;
	return 0;
} 
