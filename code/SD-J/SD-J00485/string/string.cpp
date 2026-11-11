#include<iostream>
#include<string>
#include<cstdio> 
using namespace std;
int n,ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		for(int j=1;j<=x;j++) s+=c;
	}
	for(int i=0;i<s.size()/2;i++)
		if(s[i] != s[s.size()-i-1]) ans++;
	cout<<ans;
}
