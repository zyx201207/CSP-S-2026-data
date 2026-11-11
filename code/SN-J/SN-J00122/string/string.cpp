#include<bits/stdc++.h>
using namespace std;
struct huiwen{
	int len;
	char zimu;
}a[100000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].len>>a[i].zimu;
	}
	for(int i=0;i<n;i++){
		if(a[i].zimu==a[i+1].zimu){
			cout<<0;
			break;
		}else{
			cout<<2;
		}
	}
	return 0;
}
