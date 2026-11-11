#include <bits/stdc++.h>
using namespace std;
char g;
string d;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long  a,c=0,b;
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>b>>g;
		for(int j=c;j<c+b;j++){
			d[i]=g;
		}
		c+=b;
	}
	b=0;
	for(int i=0;i<c/2;i++){
		if(d[i]!=d[c-i-1]){
			b++;
		}
	}
	cout<<b;
	return 0;
}
//6
//1000000000 a
//1000000000 a
//1000000000 a
//1000000000 b
//1000000000 b
//1000000000 b

