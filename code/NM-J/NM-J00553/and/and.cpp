#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,mmax=0,k;
	bool d=false;
	cin>>n>>m;
	int a[n+5],b[5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[j]<a[j+1]){
				k=a[j];
				a[j]=a[j+1];
				a[j+1]=k;
				d=true;
			}
		}
		if(d==false) break;
	}
	cout <<a[m];
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
