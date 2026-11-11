#include<bits/stdc++.h>
using namespace std;
int n,m,box[500001],ans[500001],wh=0;;
int cards[500001],top;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>box[i];
	}
	for(int i=1;i<=n;i++){
		top=1;
	    while(wh+i<=n){
			int pu=box[i+wh];
			cards[top]=pu;
			for(int j=1;j<top;j++){
				if(pu==cards[j]){
					top=j;
				}
			}
			wh++;
			top++;
		}
		wh=0;
		for(int y=1;y<top;y++){
			for(int z=1;z<=m;z++){
				if(cards[y]==z) ans[z]++;
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
