#include<bits/stdc++.h>
using namespace std;
int n,m;
int k[500050],a[500050],z[300030];
void c(int x,int y){
	int b=0;
	for(int j=y;j<=x-1;j++){
		if(b==1){
			a[j]=0;
		}else if(a[j]==a[x]){
			b=1;
			a[j]=0;
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>k[i];
	}

	for(int s=1;s<=n;s++){
		for(int q=s;q<=n;q++)a[q]=k[q];
		for(int i=s+1;i<=n;i++){
			c(i,s);	
		}
		for(int j=1;j<=m;j++){
			for(int i=s;i<=n;i++){
				if(a[i]!=0){
					if(a[i]==j){
						z[j]+=1;
					}				
				}
			}	
		}
	}
	for(int i=1;i<=m;i++){
		cout<<z[i]<<" ";
	}
	return 0;
}
