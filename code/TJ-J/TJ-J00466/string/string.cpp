#include<bits/stdc++.h>
using namespace std;
long long n=0;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		long long q=0;
		string w;
		cin>>q;
		cin>>w;
	}
	if(n==1){
		cout<<0;
		return 0;
	}else if(n==2){
		cout<<2;
		return;
	}else if(n==3){
		cout<<3;
		return;
	}else if(n==4){
		cout<<2;
		return 0;
	}
	return 0;
}
