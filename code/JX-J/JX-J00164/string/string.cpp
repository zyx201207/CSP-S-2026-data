#include<bits/stdc++.h>
using namespace std;
long long n,a[2000000],x=0,y=0;
char c[2000000];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		x+=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	for(int i=0;i<x;i++){
		if(s[i]!=s[x-i]){
			y++;
			s[i]=s[x-i];
		}
	}
	cout<<y<<endl;
	return 0;
}
