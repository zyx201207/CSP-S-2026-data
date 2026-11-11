#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,s=0;
	cin>>n>>m;
	int a[64000];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]<a[i+1]){
			s=a[i];
			a[i]=a[i+1];
			a[i+1]=s;
		}
		
	}
	cout<<a[m-1];
	fclose(stdin);
	fclose(stdout);
}
