#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],pd[200005],cmp=0,ans[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(n--){
		memset(pd,0,sizeof(0));
		cmp++;
		for(int i=cmp;i<=n;i++){
			pd[i]=a[i];
			for(int j=2;j<=n;j++){
				if(pd[i]==a[j]){
					memset(pd,0,sizeof(0));
					continue;
				}else{
					pd[i]=a[j];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(pd[i]==j){
				ans[j]++;
				continue;
			}
		}
	}
	memset(pd,0,sizeof(0));
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
