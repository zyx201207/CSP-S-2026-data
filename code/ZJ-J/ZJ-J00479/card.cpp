#include<bits/stdc++.h>
using namespace std;
int a[500009],b[300009],c[300009],d[300009];
int main(){
	freopen("r","card.in",stdin);
	freopen("w","card.out",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int k=1;k<=n;k++){
		for(int i=k;i<=n;i++){
			b[a[i]]++;
			if(b[a[i]]==1) c[a[i]]=i;
			if(b[a[i]]==2){
				for(int j=c[a[i]];j<i;j++) b[a[j]]-=1;
			}
		}for(int i=1;i<=n;i++){
			if(b[a[i]]==1) d[a[i]]++;
			b[a[i]]=0;
		}
	}for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
	return 0;
}