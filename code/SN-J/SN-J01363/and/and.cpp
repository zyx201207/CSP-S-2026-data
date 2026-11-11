#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	int n,c,d=0;
	char b;
	string a;
	cin>>n;
	for(int i=0;i<n;i++){
	cin>>c>>b;
	d+=c;
	for(int j=1;j<=c;j++){
	a+=b;
	}
	}
	for(int i=a.size();i>=0;i--){
	cout<<a[i];
	}
	cout<<endl;
	for(int i=0;i<=d;i++){
	cout<<a[i];
	}
	return 0;
}
