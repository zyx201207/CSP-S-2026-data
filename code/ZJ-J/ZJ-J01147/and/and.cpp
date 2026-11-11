#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,cnt[32]={},tot=0;
	cin>>n>>m;
	vector<int> a(n+1);
	vector<bool> vis(n+1,1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int b=0;b<32;b++) cnt[b]+=(a[i]&(1<<b))>>b;
	}
	for(int b=31;b>=0;b--){
		int c=0;
		tot<<=1;
		if(cnt[b]<m) continue;
		for(int i=1;i<=n;i++){
			if(!vis[i]) continue;
			vis[i]=(a[i]&(1<<b))>>b;
			if(vis[i]) c++;
		}
		if(c>=m) tot^=1;
	}
	cout<<tot;
}