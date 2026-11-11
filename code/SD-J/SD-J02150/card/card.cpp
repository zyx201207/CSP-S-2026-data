#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5,M=3e5+5;
int n,m,a[N],t[M],g[M];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!t[a[j]]){
				t[a[j]]=j;
			}else{
				for(int k=t[a[j]];k<=j-1;k++){
					t[a[k]]=0;
				}
				t[a[j]]=j;
			}
		}
		for(int j=1;j<=m;j++){
			if(t[j]){
				g[j]++;
				t[j]=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<g[i]<<" ";
	}
	return 0;
}
