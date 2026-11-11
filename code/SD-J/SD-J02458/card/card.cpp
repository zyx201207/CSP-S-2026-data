#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);		
	int n,m;
	cin>>n>>m;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int t[m+1];
	for(int i=1;i<=m;i++){
		t[i]=0;
	}
	for(int i=1;i<=n;i++){
		bool b[n+1];
		for(int j=1;j<=n;j++){
			b[j]=1;
		}
		for(int j=i;j<=n;j++){
			for(int k=i;k<j;k++){
				if(b[k]){
					if(a[k]==a[j]){
						for(int l=k;l<j;l++){
							b[l]=0;
						
						}
					}
				}
			}
		}
		for(int j=n;j>=i;j--){
			if(b[j]==0){
				continue;
			}else{
				++t[a[j]];
			}
			
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
}
