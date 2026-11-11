#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500030],b[500030],ans[300030],t[500030];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	if(n>=5000&&m>=3000){
		for(int i=1;i<=n;i++){
			scanf("%ld",&a[i]);
	//		cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				t[j]=0;
			}
			for(int j=i;j<=n;j++){
				b[j]=a[j];
				if(t[b[j]]==0){
					t[b[j]]=j;
				}else{
					for(int y=t[b[j]];y<j;y++){
						b[y]=0;
					}
					t[b[j]]=j;
				}
	
			}		
			for(int j=i;j<=n;j++){
				ans[b[j]]++;
			}
			for(int te=1;te<=n;te++){
				b[te]=0;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
	}else{
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++){
				b[j]=a[j];
				for(int x=j;x>=i;x--){
					if(b[x]==b[j]){
						for(int y=x;y<j;y++){
							b[y]=0;
						}
					}
				} 
			}for(int j=i;j<n;j++){
				ans[b[j]]++;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
	}
	
} 
