#include <bits/stdc++.h> 
using namespace std;
#define int long long
int n,a,x,s;
char b;
string c;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a>>b;
		for(int i=1;i<=a;i++){
			c+=b;
			x++;
		}
	}
	for(int i=0;i<x/2;i++){
			if(c[i]!=c[x-i]){
				s++;
			}
		}
		cout<<s;
	return 0;
}

