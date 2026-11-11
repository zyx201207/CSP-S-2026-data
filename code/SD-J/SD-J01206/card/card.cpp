#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[500005],flag=0,t[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[a[i]]++;
	}
	for(int i=1;i<n;i++){
		if(a[i]>a[i+1]){
			flag=1;
		}
	}
	if(a[n-1]>a[n]){
		flag=1;
	}
	if(flag==0){
		for(int i=1;i<=m;i++){
			cout<<t[i]<<" ";
		}
	}
	
	return 0;
} 
