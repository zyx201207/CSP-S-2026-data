#include<bits/stdc++.h>
using namespace std;
int a[100001];
int b[100001];
int c[100001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int suo=0;
		if(i<1){
			for(int j=0;j<n;j++){
				
				b[suo]=a[j];
				for(int k=0;k<j;k++){
					if(b[k]==a[j]){
						suo=k;
					}
				}
				suo++;
			}
			for(int n=0;n<suo;n++){
				c[b[n]]++;
			}
		}else{
			for(int j=i-1;j<n;j++){
				
				b[suo]=a[j];
				for(int k=i-1;k<j;k++){
					if(b[k]==a[j]){
						suo=k;
					}
				}
				suo++;
			}
			for(int n=0;n<suo;n++){
				c[b[n]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]-1<<" ";
	}
	return 0;
}
