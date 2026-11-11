#include<bits/stdc++.h>
using namespace std;
int n,m,mii[300001],a[500001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		bool f[300001][2]={0};
		for(int i=k;i<=n;i++){
			if(f[a[i]][0]==0){
				f[a[i]][0]=1;
				f[a[i]][1]=i;
			}else{
				for(int j=f[a[i]][1];j<=i-1;j++){
					f[a[j]][0]=0;
					f[a[j]][1]=0;
				}
				f[a[i]][0]=1;
				f[a[i]][1]=i;
			}
		}
		for(int i=1;i<=m;i++){
			if(f[i][0]==1){
				mii[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<mii[i]<<" ";
	}
}

