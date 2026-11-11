#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int a[N],tong[N];
bool vis[N];
int n,m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);cout.tie(nullptr); 
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vis[a[i]]=1;
	}
	int g=1;
	while(g<=n){
		//n-m+1--n;
		int i=g;
		while(i<=n){
			bool t=0;
			for(int j=i+1;j<=n;j++){
				if(a[j]==a[i]){
					i=j;
					t=1;
				} 
			}
			if(t==0){
				tong[a[i]]++;
				i++;
			} 
		}
		g++;
	} 
	for(int i=1;i<=m;i++){
		if(vis[a[i]]==1) cout<<tong[i]<<" ";
	} 
	return 0;
}
