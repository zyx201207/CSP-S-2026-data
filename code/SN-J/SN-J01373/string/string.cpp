#include<bits/stdc++.h>
using namespace std;
int n;
int a[100000000];
string c[100000000];
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","r",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	if(n==1) cout<<"0";
	if(n==2){
		if(c[1]!=c[2]){
			cout<<min(a[0],a[1]);
		}else{
			cout<<"0";
		}
	}
	if(n>2){
		if(c[n-1]==c[n]&&c[1]==c[n]){
			cout<<"0";
		}else{
			cout<<a[n];
		}
	}
	
	return 0;
} 
