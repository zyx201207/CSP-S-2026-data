#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a,c=-1;
	string s;
	for(int i=1;i<=n;i++){
		cin>>a>>s;
		c+=int(s[i]=s[a]-1+i);
	}
	cout<<c;
	return 0;
}
