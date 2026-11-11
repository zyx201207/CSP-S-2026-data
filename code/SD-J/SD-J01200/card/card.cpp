#include<iostream>
#include<cstdio>
#include<algorithm>
int n,m,a[500005],t[300005],xt[500005]; 
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		xt[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]==a[j]){
				for(int k=i;k<=j;k++){
					if(j>xt[k]&&i<xt[k]){
						xt[k]--;
					} 
				}
			}
		} 
	}
	for(int i=1;i<=m;i++){
		cout<<xt[i]<<" ";
	}
	return 0;
} 
