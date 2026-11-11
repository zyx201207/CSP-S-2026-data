#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[500005],p[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		p[0,500000]=0;
		for(int j=i;j<=n;j++){
			bool flag=true;
			for(int k=1;k<=n-i;k++){
				if(p[k]==a[j]){
					flag=false;
				}
				if(flag==false){
					p[k]=0;
				}
			}
			for(int k=1;k<=n-i;k++){
				if(p[k]==0){
					p[k]=a[j];
					break;
				}
			}
		}
		int k=1;
		while(p[k]!=0){
			ans[p[k]]++;
			k++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
