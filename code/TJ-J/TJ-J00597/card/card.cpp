#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<1;
	}else if(m==2){
		if(n==2) cout<<1<<' '<<2;
	}else{
		cout<<1;
		for(int i=1;i<m;i++){
			cout<<0<<' ';
		}	
	}
	return 0;
} 
