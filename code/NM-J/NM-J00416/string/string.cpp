#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	int n;
	string a,b;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		if(a[2]>a[1]){
			cout<<a[1];
		}else{
			cout<<a[2];
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(b[i]==b[i-1]){
			cout<<0;
			return 0;
		}


	}
	cout<<1;
	return 0;
}
