#include<bits/stdc++.h>
using namespace std;
int n,m;
string a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>a>>m>>b;
	if(n!=m){
		cout<<"0000";
		return 0;
	}
	if(a[0]!=b[0]||a[1]!=b[1]){
		cout<<"1000";
		return 0;
	}
	if(a[2]>='D'&&b[2]<='C'||a[2]<='C'&&b[2]>='D'){
		cout<<"1100";
		return 0;
	}
	if(abs(a[2]-b[2])!=1){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}