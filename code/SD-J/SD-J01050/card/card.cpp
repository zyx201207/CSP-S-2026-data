#include<bits/stdc++.h>
using namespace std;
int n,m;
int tong[300001],cun[3000001],a[500001],cun2[3000001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cun[j]=0,cun2[j]=0;
		for(int j=i;j<=n;j++){
			tong[a[j]]+=1;
			if(cun[a[j]]==0){
				cun[a[j]]=1;
			}
			else if(cun[a[j]]==1){
				for(int k=j-1;k>=i;k--){
					if(cun2[k]==0){
						tong[a[k]]--;
						cun2[k]=1;
					}
					if(a[k]==a[j]) break;
				}
				continue;
			}
		}
//		for(int i=1;i<=n;i++){
//			tong[a[i]]+=cun2[a[i]]
//		}
	}
	for(int i=1;i<=m;i++){
		cout<<tong[i]<<" ";
	}
	return 0;
}
