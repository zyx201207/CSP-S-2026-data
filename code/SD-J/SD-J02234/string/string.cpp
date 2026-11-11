#include <bits/stdc++.h>
using namespace std;
int n[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a;
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>n[i];
		string b;
		cin>>b;
	}
	long long c=0; 
	for(int i=1;i<=a;i++){
		c+=n[i];
	}
	cout<<c/2;
	return 0;
}
