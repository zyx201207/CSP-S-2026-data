#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a,b,e=0,g=0;
	string c,f="";
	char d;
	cin>>a;
	for(int i = 0;i < a;i++){
		cin>>b>>d;
		e += b;
		for(int j = 0;j < b;j++){
			c = c + d;
		}
	}
	for(int i = 0;i < e;i++){
		if(i < e / 2){
			f = f + c[i];
		}
		else if(e % 2 == 0 or i != e / 2){
			if(f[e-i-e%2] != c[i]){
				g++;
			}
		}
	}
	cout<<g;
	return 0;
}
