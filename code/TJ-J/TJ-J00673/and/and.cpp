#include<bits/stdc++.h>
using namespace std;	
int a[20001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,max=-1;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if((a[i]&a[i+j])>max) max=a[i]&a[i+j];
		}
	}
	cout<<max;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
