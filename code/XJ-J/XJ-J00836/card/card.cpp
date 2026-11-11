#include<bits/stdc++.h>
using namespace std;
const int N=1e5*5+10;
int a[N];
int b[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("cars.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(b[j]==a[i]){
				for(int k=1;k<i;k++){
					b[k]=0;
				}
				b[i]=a[i];
			}
			else{
				b[i]=a[i];
			}
		}	
	}
	for(int i=1;i<=n;i++){
		cout<<b[i];
	}	

	
	
	
	return 0;
}	