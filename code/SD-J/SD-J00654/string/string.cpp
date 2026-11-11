#include<bits/stdc++.h>
using namespace std;
long long n,a,c=0,ans;
char b;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int j=1;j<=a;j++){
			s+=b;
			c++;
		}
	}
	for(int i=0;i<c/2;i++){
		if(s[i]!=s[c-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
