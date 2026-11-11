#include<bits/stdc++.h>
using namespace std;
const int N=100007;
int n,m,a[N],b[N],k[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int p=1;p<=n;p++){
		for(int i=p;i<=n;i++){
			for(int j=1;j<=i;j++){
				if(a[i]==a[i-j]){
					for(int u=i-j;u<i;u++){
						b[u]=0;	
					}
				}
			}
		}
	
		for(int i=p;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(b[i]==j){
					k[j]++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			b[i]=a[i];
		}		
	}

	for(int i=1;i<=m;i++){
		cout<<k[i]<<" ";
	}
	return 0;
} 
