#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int __=1;
int n,m,a[N],pos[N],ans[N];
bool vis[N];
stack<int> s;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				vis[a[j]]=1;
				pos[a[j]]=j;
			}else{
				for(int k=pos[a[j]];k<j;k++) vis[a[k]]=0,pos[a[k]]=0;
				vis[a[j]]=1;
				pos[a[j]]=j;
			}
		}
		for(int j=1;j<=m;j++){
			if(vis[j]) ans[j]++;
			vis[j]=0,pos[j]=0;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	//cin>>__;
	while(__--) solve();
	return 0;
}

