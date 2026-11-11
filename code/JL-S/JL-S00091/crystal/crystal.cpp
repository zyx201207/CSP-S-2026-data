#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,s=1;
	cin>>n>>m;
	int a[n];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int l=1;l<=n;l++){
		if(a[l]>a[l+1]){
			swap(a[l],a[l+1]);
		}
	}
	for(int i=1;i<=n;i++){
		if(m/i>=a[i+1]-a[i]&&m/i>=a[i]-a[i+1]){
			if(a[i+1]-a[i]>0){
				m=m-a[i+1]*i+a[i]*i;
			}else m=m-a[i]*i+a[i+1]*i;
			s++;
		}
	}
	//for(int l=1;l<=n;l++) cout<<a[l];
	cout<<s;
}
