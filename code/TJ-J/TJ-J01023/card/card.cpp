#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin)
	freopen("card.out","w",stdout)
	int n,m,i,j,a[100],ans[100],k;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
		
	}
	 for(j=1;j<=n;j++){
	 	a[n]=k;
	 	ans[k]=n;
	 	for(b=1;b<=m&&b!=k;b++){
			if(a[j]==a[b]){
				ans[b]++;
			}
			
		}
	}
	for(b=1;b<=m;b++){
	cout<<ans[b]<<" ";	
	}
	
	
	
	fclose(stdin)
	fclose(stdout)
	return 0;
	
}
