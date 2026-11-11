#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,a[N],v[N],vis[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i-1]==a[i]){
				v[i-1]=v[i]=1;
			}
		}
		for(int j=1;j<=n;j++){
			if(!v[j]){
				vis[a[j]]+=1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<vis[i]<<' ';
	}
	return 0;
}
