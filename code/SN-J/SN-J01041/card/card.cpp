#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],cnt[300010],b[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int l=1;l<=n;l++){
		for(int i=l;i<=n;i++){
			for(int j=1;j<=i-1;j++){
				if(b[j]==a[i]){
					for(int k=j;k<=i-1;k++){
						b[k]=0;
					}
				}
			}
			b[i]=a[i];
		}
		for(int i=1;i<=n;i++)cnt[b[i]]++;
		for(int i=1;i<=n;i++)b[i]=0;
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<" "; 
	return 0;
}
