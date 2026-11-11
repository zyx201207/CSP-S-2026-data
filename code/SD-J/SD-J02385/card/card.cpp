#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000000],ans[1000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			int s=0;
			for(int k=j;k<=n;k++){
				if(a[k]==i)s++;
			}if(s>0) ans[i]++;
		}cout<<ans[i]<<" ";
	}
	return 0;
}
