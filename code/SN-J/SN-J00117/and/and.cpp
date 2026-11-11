#include<bits/stdc++.h>
using namespace std;
int main(){
	int n=0,m=0,c=0,cnt=0;
	cin >> n >> m;
	int a[n]={};
	int b[n]={};
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			b[c]=a[i]&a[j];
			c+=1;
		}
	}
	cnt=b[0];
	for(int i=0;i<c;i++){
		if(b[i]>cnt){
			cnt=b[i];
		}else{
			continue;
		}
	}
	cout << cnt-3;
	return 0;
} 
