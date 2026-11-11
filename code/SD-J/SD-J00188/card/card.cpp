#include<bits/stdc++.h>
using namespace std;
struct node{
	int shu,st;
}tong[300005];
int n,m,a[200005],aa[200005],ans[300005];
int main(){
	freopen("card.in",'r',stdin);
	freopen("card.out",'w',stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(tong,0,sizeof tong);
		for(int l=1;l<=n;l++){
			aa[l]=a[l];
		}
		for(int p=i;p<=n;p++){
			if(tong[aa[p]].shu==1){
				for(int k=tong[aa[p]].st;k<=n;k++){
					aa[k]=0;
					tong[a[k]].shu=0;
				}
				tong[aa[p]].shu=1;
				tong[aa[p]].st=p;
			}else{
				tong[aa[p]].shu=1;
				tong[aa[p]].st=p;
			}
		}
		for(int j=1;j<=300005;j++){
			if(tong[j].shu==1){
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=300005;i++){
		if(ans[i]!=0){
			cout<<ans[i]<<' ';
		}
		
	}
	return 0;
} 
