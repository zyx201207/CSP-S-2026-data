#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n],b[m],r,c[m];
	for(int i=0;i<n;i++){
		cin>>a[n];
	}
	for(int i=0;i<n;i++){
		r=0;
		for(int j=i;i<n;j++){
			b[r]==a[j];
			for(int k=0;k<r;k++){
				if(b[k]==b[r]){
					r=k;
					break;
				}
			}
		}
		for(int j=0;j<r;j++){
			c[b[j]-1]++;
		}
	}
	for(int i=0;i<m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
