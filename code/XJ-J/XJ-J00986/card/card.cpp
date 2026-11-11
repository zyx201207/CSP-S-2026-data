#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int n,m,a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int c[m+5]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int b[N] = {0};
		for(int j=1;j<=n;j++){
			b[j]=1;
		} 
		for(int k=i;k<=n;k++){
			for(int j=n;j>k;j--){
				if(a[j]==a[k]){
					for(int l=k;l<=j-1;l++){
						b[l]=0;
						k = j;
					}
					break;
				}
			}
		}
		
		int d[m+5]={0};
		for(int j=i;j<=n;j++){
			if(b[j]==1&&d[a[j]]==0){
				c[a[j]]++;
				d[a[j]] = 1;
			} 
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
	return 0;
}
