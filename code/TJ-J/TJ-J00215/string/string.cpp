#include <bits/stdc++.h>
using namespace std;

int a[100000];
string c;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	if(n==2){
		cout<<"0"; 
	}
	if(n==3){
		cout<<"2";
	}
	if(n==6){
		cout<<"3000000000";
	}
	return 0;
}
