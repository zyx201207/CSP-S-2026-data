#include<bits/stdc++.h>
using namespace std;
int a[10009];
int n,m,ma=0;
int main(){
	freopen("string.in","r","stdin");
	freopen("string.out","w","stdout");
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ma=max(ma,a[i]);
		}
	}
	else{
		for(int i=1;i<=n;i++){
			ma=max(ma,a[i]&a[i+1]);
		}
	}
	cout<<ma;
	return 0;
}
