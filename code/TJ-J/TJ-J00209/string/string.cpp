#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
#define int long long
const int N=2e5+5;
int n;
int a[N];
char c[N];
int l=0,r=0;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)s+=c[i];
	}
	int ans=0;
	r=s.size()-1;
	while(l<r){
		ans+=(s[l]!=s[r]);
		++l;
		--r;
	}
	cout<<ans;
	return 0;
}
