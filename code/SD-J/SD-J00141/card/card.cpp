#include<bits/stdc++.h>
using namespace std;
int n,m,a[500002],b[300002];
struct node{
	int sum,id;
}f[300002];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	int k=0;
	while(k!=1){
		for(int i=1;i<=n;++i){
			if(f[a[i]].id!=-1){
				if(f[a[i]].sum==1){
					for(int j=f[a[i]].id;j<=i;++j){
						k--;
						f[a[i]].sum=0;
					}
					f[a[i]].id=-1;
				}
				else if(f[a[i]].sum==0){
					f[a[i]].sum=1;
					f[a[i]].id=i;
					k++;
				}
			}
		}
		for(int i=1;i<=k;++i){
			if(f[a[i]].sum==1){
				b[a[i]]++;
			}
		}
	}
	for(int i=1;i<=m;++i){
		cout<<b[i]<<" ";
	}
	return 0;
}
/*
4 3 
1 2 1 3
*/
