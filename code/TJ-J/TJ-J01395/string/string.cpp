#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	char x;
	char x1;
	long long ai;
	long long xchange=0;
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>ai;
		cin>>x;
		x1=x;
		if(x!=x1){
			xchange++;
		}
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(xchange==0){
		cout<<0;
		return 0;
	}
	return 0;
}
