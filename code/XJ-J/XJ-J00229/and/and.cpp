#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r"stdin);
	freopen("and.out","w"stdout);
	int n,m,a[10000],mmm=0,mm=n;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i]; 
	}
	for(int i=0;i<m;i++){
		
		for(int j=0;j<n;j++){
			mmm=0;
			if(a[j]>=mmm){
				mmm=a[j];
				mm=j;
			}
			a[mm]==0;
		}
	}
	cout<<mmm;
	return 0; 
}
