#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,suma=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==n){
		for(int i=1;i<n;i++){
			suma=a[i]&a[i+1];
		}
		cout<<suma;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<n;j++){
			int x=a[i]&a[j];
			suma=max(suma,x);	
		}
	}
	cout<<suma;
	return 0;
} 
