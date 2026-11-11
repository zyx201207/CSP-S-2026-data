#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdio> 
#include<algorithm>
#define ll long long
using namespace std;//  :)
const int N=2*10e5+10;
int n;
string s;
int a,l,b=0,ans=0;
string c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	l=s.size();
	for(int i=0;i<=l/2;i++){
		if(s[i]!=s[l-i-1]){
			b=1;
			ans++;
		}
	}
	if(b==0){
		cout<<0;
		return 0;
	}
	cout<<ans;
	return 0;
}
