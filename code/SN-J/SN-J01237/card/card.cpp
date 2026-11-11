#include<bits/stdc++.h> 
using namespace std;
const int N=1e7+10;
int n,m,a[N],ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i]==a[j]){
				for(int k=i;k<j;k++){
					a[k]=0;
				}	
			}  
			for(int l=1;l<=n;l++){
				for(int v=1;v<=m;v++){
					if(a[i]==v){
						ans[v]++;
					}
				}
			}                         
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
