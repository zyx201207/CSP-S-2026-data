#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],M[300005],c;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int b[500005];
		for(int j=1;j<=n;j++) b[j]=0;
		for(int j=i;j<=n;j++) b[j]=a[j];
		for(int j=i;j<=n;){
			for(int k=j;k<=n;k++){
				if(M[a[k]]){
					j=k;
					for(int q=M[a[k]];q<k;q++){
						b[q]=0;
						M[a[q]]=0;
					}
					M[a[k]]=k; 
				}
				else M[a[k]]=k;
			}
			j++;
		}	
		for(int j=1;j<=n;j++){
			ans[b[j]]+=1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
