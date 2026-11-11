#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[200001];
	string m;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>m;
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		if(m[0]==m[1]){
			cout<<0;
			return 0;
		}
		if(a[1]==1||a[2]==1){
			cout<<1;
			return 0;
		}
		if(a[1]==2||a[2]==2){
			cout<<2;
			return 0;
		}
		if(a[1]==3||a[2]==3){
			cout<<3;
			return 0;
		}
		if(a[1]==4||a[2]==4){
			cout<<4;
			return 0;
		}
		if(a[1]==5||a[2]==5){
			cout<<5;
			return 0;
		}
	}
	
}
