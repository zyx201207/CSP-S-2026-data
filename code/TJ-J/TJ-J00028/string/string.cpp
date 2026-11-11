#include<bits/stdc++.h>
using namespace std;
int a,b,n;
char s,t;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n>>a;
    if(n!=1) {
	cin>>s>>b>>t;
	if(s-'0'==t-'0'){	
	cout<<"0";
	return 0;
	}
	if(min(a,b)==b)
	swap(a,b);
	if(a%2==0){
		cout<<a/2;
		return 0;
	}else{
		cout<<b/2;
		return 0;
	}
	}else cout<<"0";
	return 0;
}
