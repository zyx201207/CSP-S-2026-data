#include<bits/stdc++.h>
using namespace std;
int n,l,a,ans;
char b;
string s,c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a>>b;
		for(int i=1;i<=a%10;i++) s+=b;
		for(int i=1;i<=a/10;i++) s+=b,s+=b,s+=b,s+=b,s+=b,s+=b,s+=b,s+=b,s+=b,s+=b;
	}
	int l=s.size();
	for(int i=l-1;i>=0;i--) c+=s[i];
	for(int i=0;i<l/2+1;i++){
		if(s[i]!=c[i]){
			s[i]=c[i];
			c[l-i-1]=c[i];
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
