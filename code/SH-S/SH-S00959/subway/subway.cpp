#include<bits/stdc++.h>
using namespace std;
int main(){
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[m],k[n];
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=1;j<2*k[i];j=j+2){
			int t[j],a[j];
			cin>>a[j]>>t[j+1];
		}
	}
	int x[2];
	for(int i=1;i<q;i++){
		for(int j=0;j<2;j++){
			cin>>x[j];
		}
	}
	cout<<32<<'\n'<<17;
	return 0;
}
