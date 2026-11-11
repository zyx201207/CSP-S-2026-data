#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5;
ll n,a[N],ans,x;
char c[N];
string s;
bool f(string str){
	bool flag=true;
	for(int i=0;i<str.size()/2;i++){
		if(s[i]!=s[str.size()-1-i]) flag=false;
	}
	return flag;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	x=a[1];
	for(int i=2;i<=n;i++){
		x=__gcd(x,a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i]/x;j++){
			s+=c[i];
		}
	}
	if(f(s)) cout<<0;
	else{
		for(int i=0;i<s.size()/2;i++){
			if(s[i]!=s[s.size()-1-i]){
				ans++;
			}
		}
		cout<<ans*x;
	}
	
	return 0;
}
