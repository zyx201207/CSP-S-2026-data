#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	long long a[n+1],b[n+1],c[n+1]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=n;j++){
			if(b[j]!=a[i]){
				b[j]=a[i];
			}
		}
	}
	int t=1,p=1;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(c[k]==a[j]){
					t=0;
					while(c[k]!=0){
						c[k]=0;
						k++;
					}
				}
			}
			if(t==1){
				c[p]=a[j];
				a[j]=0;
			}
		}
		for(int j=1;j<=n;j++){
			if(b[j]==a[i]){
				cout<<a[i];
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
