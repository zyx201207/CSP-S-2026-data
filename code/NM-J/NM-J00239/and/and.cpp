#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int a[n+5],b[n+5]={0},d[n*(n-m+1)]={0},c=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		int j=0.1;
		while(a[n]){
			c=a[n]%2;
			b[i]+=c*j*10;
			j*=10;
			a[n]/=2;
		}
	}for(int i=1;i<=n*(n-m+1);i++){
		int j=2;
		d[i]=b[j];
		while(m){
			d[i]=d[i]&b[j+1];
			j++;
			m--;
		}
	}sort(d[i]+1,d[i]+n*(n-m+1)+1);
	cout<<d[n*(n-m+1)];
	return 0;
}
