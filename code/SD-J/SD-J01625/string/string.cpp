#include <bits/stdc++.h>
using namespace std;
long long a,b,r=0;
string c="0";
char d;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>b>>d;
		for(int j=1;j<=b;j++){
			c+=d;
		}
	}
	for(int i=1,j=c.size();i<=c.size()/2;i++,j--){
		if(c[i]!=c[j])r++;
	}cout<<r;
	return 0;
}
