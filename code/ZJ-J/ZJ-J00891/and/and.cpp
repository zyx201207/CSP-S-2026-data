#include<bits/stdc++.h>
using namespace std;
int n,i,j,m,k,ans,a[200100],e[200100],f[42];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	memset(e,1,sizeof(e));
	for(i=1;i<=n;i++){
		cin>>a[i];
		for(j=0;j<30;j++){
			if(a[i]&(1<<j)){
				f[j]++;
			}
		}
	}for(j=29;j>=0;j--){
		if(f[j]>=m){
			for(i=1;i<=n;i++){
				if(a[i]&(1<<j)||!e[i]){
					continue;
				}else{
					for(k=0;k<30;k++){
						if(a[i]&(1<<k)){
							f[k]--;
						}
					}e[i]=0;
				}
			}ans+=(1<<j);
		}
	}cout<<ans;
	return 0;
}
