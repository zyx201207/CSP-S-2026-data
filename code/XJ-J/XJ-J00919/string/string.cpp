#include<bits/stdc++.h>
using namespace std;
int n,a,num,he=0;
string c;
char b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a>>b;
		for(int j=0;j<a;j++) c+=b;
		num+=a;
	}
	int shu=num;
	for(int i=num/2;i>0;i--){
		if (c[i]!=c[shu]) he++;
		shu--;
	}
	cout<<he-1;
	return 0;
}