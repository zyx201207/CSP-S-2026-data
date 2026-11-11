#include<bits/stdc++.h> 
using namespace std;
long long int n,m,x=0,z=1,minn,a[100000000];
int main(){
	cin>>n>>m;
	for(int i=0 ; i<n ; i++){
		cin>>a[i];
		if(a[i]<=minn){
			minn=a[i];
		}
	}
	for(int i=0 ; i<n ; i++){
		if(a[i]==minn){
			a[i]+1;
			m--;
		}
		if(m==0){
			break;
		}
	}
	for(int i=0 ; i<n ; i++){
		if(a[i]==a[i+1]){
			z++;
		}
	}
	cout<<z+2;
	return 0;
}
