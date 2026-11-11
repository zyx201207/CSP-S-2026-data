#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	int cnt =0;
	cin>>n>>m;
	int a[n+1]={0};
	int b[n+1]={0};
	int c[n+1]={0}; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;i<=n;j++){
			if(a[j]>0){
				b[j]=a[j];
			}
			for(int k=1;k<i;k++){
				if(b[i]=b[k]){
					cnt++;
				}
			}
			if(cnt==1){
				for(int k=1;k<=i;k++){
					b[k]=0;
				}
				for(int k=1;k<i;k++){
					a[k]=0;
				}
			}
			cnt=0;
		}
		for(int j=1;j<=n;j++){
			if(b[j]>0){
				c[b[j]]++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<c[i];
	}
	return 0;
}
