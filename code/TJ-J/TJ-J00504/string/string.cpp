#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m[n+1];
	string l[n],s[110000];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i]>>l[i];
	}
	cout<<m<<l;
	return 0;
}
