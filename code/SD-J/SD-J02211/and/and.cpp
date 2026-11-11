#include<bits/stdc++.h>
using namespace std;
int a[200050],b[200050];
bool abb(int m){
	bool abb1=1;
	for(int i=1;i<m;i++){
		if(a[i]!=a[i+1]){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxa=0,maxr=0,n1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxa=max(a[i],maxa);
	}
	if(m==1){
		cout<<maxa;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[n-i+1];
	}
	if(m==2){
		cout<<b[2];
		return 0;
	}
	if(m==n-1){
		cout<<b[n-1];
	}
	if(abb(m)==1){
		cout<<b[1];
		return 0;
	}
	cout<<b[m];
	return 0;
}
