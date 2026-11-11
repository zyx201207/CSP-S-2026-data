#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],b[500005],c[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int l=1;l<=n;l++){
		int w=n;
		for (int i=1;i<=n;i++){
			b[i]=a[i];
		}
		for(int i=l;i<=w;i++){
			for (int j=l;j<i;j++){
			    if(b[j]==b[i]&&b[j]!=0){
			    	for (int k=0;k<=i-j;k++){
			    		b[j+k]=b[i+k];
			    		b[i+k]=0;
					}
					i=j+1;
				}
			}
		}
		for (int i=l;i<=n;i++){
			c[b[i]]++;
		}
	}
	for (int i=1;i<=m;i++){
    	cout<<c[i]<<" ";
    }
	return 0;
}