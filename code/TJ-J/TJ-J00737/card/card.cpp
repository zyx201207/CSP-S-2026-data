#include <bits/stdc++.h>
using namespace std;
int a[1000007],b[1000007],c[1000007];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int k=1;k<=n;k++){
		for(int j=k;j<=n;j++){
			b[j]=a[j];
			for(int s=k;s<=j;s++){
				if(b[s]==a[j]){
					for(int h=s+1;h<=j;h++){
						b[h]=0;
					}
				}
			}
		}
		for(int g=1;g<=n;g++){
			c[b[g]]++;
			b[g]=0;	
	    }
	}
	for(int i=1;i<=m;i++){
		cout << c[i] << " ";
	}
	return 0;
}

