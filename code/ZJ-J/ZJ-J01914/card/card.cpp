#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],ans[M],t[N],vis[M],cnt;
//bool A=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
//		if(A&a[i]<=a[i-1])A=0;
	}
	for(int i=1;i<=n;++i){
		cnt=0;
		memset(vis,0,m*4+8);
		for(int j=i;j<=n;++j){
			if(!vis[a[j]]){
				t[++cnt]=a[j];
				vis[a[j]]=cnt;
			}
			else{
				for(int k=vis[a[j]]+1;k<=cnt;++k){
					vis[t[k]]=0;
				}
				cnt=vis[a[j]];
			}
		}
		for(int j=1;j<=cnt;++j){
//			cout<<t[j]<<' ';
			++ans[t[j]];
		}
//		cout<<'\n';
	}
	for(int i=1;i<=m;++i){
		cout<<ans[i]<<' ';
	}
}

