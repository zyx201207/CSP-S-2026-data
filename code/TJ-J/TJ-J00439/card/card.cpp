#include <bits/stdc++.h>
#include <cstdio>
int a[500005],c[500005],b[500005],n,m;
using namespace std;
int main(){
	freopen("card.in","r",stdin);
   	freopen("card.out","w",stdout);
   	cin>>n>>m;
	for(int i=1;i<=n;i++){
			cin>>c[i];
	}
	for(int f=1;f<=n;f++){
		for(int g=1;g<=n;g++){
			a[g]=c[g];
		}
		for(int i=f;i<=n;i++){
			for(int j=i+1;j<=n-1;j++){
				if(a[i]==a[j]){
					for(int k=i;k<j;k++){
						a[k]=0;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]!=0){
				b[a[i]]++;
			}
		}
    }
    for(int i=1;i<=m;i++){
    	cout<<b[i]<<" ";
	}
	return 0;
}
