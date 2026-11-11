#include <bits/stdc++.h>
using namespace std;
int n,m,ans; 
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int a[100000];
	for(int i=0;i<n;i++){
		cin>>a[i];
		
	}
	for(int i=0;i<n*n;i++){
		int b[100001],c=0;
		for(int k=0;k<n;k++){
			b[k]=a[k];
		}	
		for(int q=0;q<=n;q++){
			for(int t=0;t<=n;t++){
				b[q]+=m-q;
			}
		}	
		for(int j=0;j<=n;j++){
			for(int w=0;w<w;w++){
				if(b[j]==b[w+1]){
					c++;
				}
			}
		}
		if(ans<c){
			ans=c;	
		}
	}
	cout<<ans;
	return 0; 
} 
