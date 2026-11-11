#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	string s,ch;
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}if(n==2){
		int a,c;
		char b,d;
		cin>>a>>b;
		cin>>c>>d;
		cout<<min(a,c);
	}
	return 0;
}
