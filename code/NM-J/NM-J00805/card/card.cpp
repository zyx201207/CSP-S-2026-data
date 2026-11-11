#include<bits/stdc++.h>
using namespace std;
int n,m,s1=0,s2=0,s3=0;
int a[1000000];
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int z=n;
	while(n--){
		for(int i=z-n;i<n;i++){
			for(int j=z-1+i;j<=n;j++){
				if(a[j]==a[i]){
					for(int h=j;h<n;h++){
						a[h]=a[h+1];
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]==1) s1++;
			if(a[i]==2) s2++;
			if(a[i]==3) s3++;
		}
	}
	cout<<s1<<" "<<s2<<" "<<s3;
	return 0;
}
