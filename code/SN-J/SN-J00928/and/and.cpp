#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	int b=0;
	int c=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]<=a[i+1]){
			b=a[i+1];
		}
		
	}
	for(int i=0;i<n;i++){
		if(b>a[i]&&a[i]>a[i+1]){
			c=a[i];
		}
	}
	cout<<c;
	return 0;
}
