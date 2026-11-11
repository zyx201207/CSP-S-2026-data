#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],z;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[j]>a[i]){
				z=a[i];
				a[i]=a[j];
				a[j]=z;
			}
		}
	}
	if(n==m){
		cout<<a[n-1];
	}
	else {
		if(m==1){
			cout<<a[0];
		}
		else if(m==n-1){
			cout<<a[m-1];
		}
		else{
			if(m==2){
				cout<<a[1];
			}
			else{
				cout<<a[m-1];
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
