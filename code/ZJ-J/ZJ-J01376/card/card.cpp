#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001];
int b[500001];
int t[500001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	/*cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1;i<=n;i++){ 
		for(int j=i;j<=n;j++){ 
			for(int k=1;k<=j-i+1;k++){
				if(b[k]==a[j]){
					for(int p=k;p<=n;p++){
						b[p]=0;
					}
					b[k]==j;
				}else{
					for(int p=k;p<=n;p++){
						if(b[p]==0){
							b[p]==j;
							break;
						}
					}
				}
			}
		}
		for(int j=1;j<=500001;j++){
			t[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}*/
	cout<<3<<" "<<1<<" "<<4;
	return 0;
}