#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a[100]=0;
	int n=0,max=0;
	cin>>n;
	for(int i=0;i<=n;i++){
		cin>>a[i];
	}
	for(int j=0;j<=n;j++){
		if(j==j+n-1){
			cout<<0;
		}else{
			if(j==n){
				max=j-n-1;
			}
		}
	}
	cout<<max;
	return 0;
}
