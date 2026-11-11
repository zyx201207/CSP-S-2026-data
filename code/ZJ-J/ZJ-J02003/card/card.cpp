#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m,a[50005],b[50005]={0},t[30005],c=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		if(b[c]!=a[i]){
			b[c]=a[i];
			c+=1;
			t[a[i]]++;
			
		}else{
			t[a[i]]++;
			
			for(int j=i;j<=n;j++){
				
				a[j]=0;
			}
		}
	}for(int i=1;i<=m;i++){
		cout<<t[m]<<' ';
	}
	return 0;
}
