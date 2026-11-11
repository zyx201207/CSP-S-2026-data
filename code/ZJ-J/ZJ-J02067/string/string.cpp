#include<bits/stdc++.h>
using namespace std;
long long n,a,ans;
char b;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int j=1;j<=a;j++){
			s=s+b;
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]!=s[s.size()-i-1]){
			ans++;
			s[s.size()-i-1]=s[i];
		}
	}
	cout<<ans;
	return 0;
}
