#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,sum=INT_MAX;
	cin>>n>>m;
	int a[n];
	int b[m];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[j]>a[i]){
				int t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	for(int i=n-m-1;i>-1;i--){
		for(int j=n-1;j>-1;j--){
			if(i==j){
				continue;
			}
			if(m==0){
				break;
			}
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
