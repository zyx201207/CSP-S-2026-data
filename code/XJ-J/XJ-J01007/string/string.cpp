#include<bits/stdc++.h>
using namespace std;
string t;
long long x,n,z;
long long a[300000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>t[i];
	}
	for(int i=1;i<=(n+1)/2;i++){
		if(t[i]!=t[n-i+1]){
			z+=a[i];
		}
	}
	cout<<z;
	return 0;
}