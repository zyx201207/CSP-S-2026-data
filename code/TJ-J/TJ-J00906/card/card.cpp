#include<bits/stdc++.h>
using namespace std;
long long n,m,a[600000],ans[600000],vis[600000];
stack<long long> f;
void l(int x){
	for(int i=x;i<=n;i++){
		while(vis[a[i]]>=1){
			long long h=f.top();
			vis[h]--;
			f.pop();
		}
		f.push(a[i]);
		vis[a[i]]++;
	}
	while(!f.empty()){
		ans[f.top()]++;
		f.pop();
	}
	for(int i=1;i<=m;i++){
		vis[i]=0;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++) l(i);
	for(int i=1;i<=m;i++) cout<<ans[i]<<" "; 
	return 0;
} 
