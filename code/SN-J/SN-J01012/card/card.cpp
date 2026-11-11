#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in ","r",stdin);
	freopen("card.out","w",stdin);
	int n,m,a[500010];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	int ans[500010];
	for(int i=1;i<=n;i++){
		int b[500010];
		for(int j=i+1;j<=n;j++){
			int q=0;
			b[j]=a[j];
			for(int k=i+1;k<=j;k++){
				if(b[k]==b[j]){
				 	b[k]=0;
				 	q=1;
				}
			}
			if(q){
				b[j]=0;
			}
		}
		for(int x=i+1;x<=n;x++){
			if(d[x]!=0])ans[a[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans;
	}
	return 0;
}
