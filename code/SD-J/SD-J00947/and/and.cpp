#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int a[20005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	int maxx=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			maxx=max(maxx,(a[i]&a[j]));
		}
	}
	cout<<maxx; 
	return 0;
}
