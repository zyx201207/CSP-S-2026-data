#include<bits/stdc++.h>
using namespace std;

long long m,n,i,a[100000];
int main(){
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<n;i++){
    	cin>>a[i];
	}
	int h[100000],f[100000],sl=0;
	for(int i=1;i<=n;i++){
		sl=i;
		for(int j=i+1;j<=n;j++){
			if(a[i]==a[j]){
				int b=j-i+1;
				int d=n-b;
				sl=d;
			}
			
		}
		
		
	}
for(int i=1;i<n;i++){
	
    cout<<h[i]<<" ";
}
    
	

}
