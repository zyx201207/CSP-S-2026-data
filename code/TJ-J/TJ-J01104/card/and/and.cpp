#include<bits/stdc++.h>
using namespace std;
int m,n,max1=0;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>m>>n;
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		 for(int j=i+1;j<m;j++){
		 	int max2=a[i]&a[j];
		 	max1=max(max1,max2);
		 }
	} 
	
	fclose(stdin);
	fclose(stdout);
}
