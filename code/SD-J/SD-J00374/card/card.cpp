#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7,M=3e5+7;
int n,m,a[N];
int val[N],vis[N];
int last[N],ok[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		vis[i]=last[a[i]];
		last[a[i]]=i;
	}
	//for(int i=1;i<=n;i++)cout<<vis[i]<<" ";
	//cout<<"\n";
	for(int i=n;i>=1;i--){
		for(int j=i;j<=n;j++){
			//cout<<j<<" ";
			ok[a[j]]=1;
			if(vis[j])j=vis[j]-1;
		}
		//cout<<"\n";
		for(int j=1;j<=m;j++){
			val[j]+=(ok[j]);
			ok[j]=0;
		}
//		for(int i=1;i<=m;i++)cout<<vis[i]<<" ";
//		cout<<"\n";
	}
	for(int i=1;i<=m;i++)cout<<val[i]<<" ";
	cout<<"\n";
//	for(int i=1;i<=m;i++)cout<<n-val[i]<<" ";
//	cout<<"\n";
	return 0;
}
