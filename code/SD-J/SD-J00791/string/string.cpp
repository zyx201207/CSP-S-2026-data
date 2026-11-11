#include<bits/stdc++.h>
using namespace std;
struct x{
	int a;
	char b;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,h=0,f=0;
	cin>>n;
	string c="";
	x s[200005];
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b;
		h+=s[i].a;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=s[i].a;j++){
			c+=s[i].b;
		}
	}
	for(int i=0;i<h/2;i++){
		if(c[i]!=c[h-i-1]) f++;
	}
	cout<<f;
	return 0;
} 
