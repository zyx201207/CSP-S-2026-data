#include<bits/stdc++.h>
using namespace std;
int a[500004];
int b[300004];
int c[300004];
int n,m;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[a[j]]!=j){
				j=b[a[j]];
				c[a[j]]++;
			}else{
				c[a[j]]++;
			}
		}
	}
	cout<<c[1];
	for(int i=2;i<=m;i++){
		cout<<' '<<c[i];
	}
	return 0;
}
