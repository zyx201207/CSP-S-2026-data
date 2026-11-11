#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
char c[1000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	if(n==1||n==0){
		cout<<"0";
		return 0;
	}
	if(n==2){
		if(c[1]==c[2]){
			cout<<0;
			return 0;
		}
		else{
			if(a[1]>=a[2]){
				cout<<a[2];
			}
			else{
				cout<<a[1];
			}
		}
	}
	return 0;
}