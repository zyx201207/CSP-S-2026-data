#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[10001];
	char x[100001];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>x[i];
	}
	if(n==1){
		cout<<"0";
	}
	int f=0;
	for(int i=1;i<=n;i++){
		if(x[1]!=x[i]){
			f=1;
		}
	}
	if(f==0){
		cout<<0;
	}
	return 0;
}
