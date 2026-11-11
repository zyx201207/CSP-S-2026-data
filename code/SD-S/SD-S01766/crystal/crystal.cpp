#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int c=0;
	int b=m;
	for(int i=1;i<=m;i++){
		if(a[1]<a[2]){
			a[1]++;
			m--;
		}
	}
	for(int i=1;i<=m;i++){
		if(a[1]<a[3]&&a[2]<a[3]){
			a[1]++;
			m--;
			a[2]++;
			m--;
		}
	}
	for(int i=1;i<=b;i++){
		if(a[i]=a[i+1]){
			c++;
		}
	}
	cout<<c-1;
	return 0;
} 

	

