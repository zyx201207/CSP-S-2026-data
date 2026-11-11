#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int n;
string s="";
string k="";
int ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		while(x--){
			s+=y;
		}
	}
	
	for(int i=s.size()-1;i>=0;i--){
		k+=s[i];
	}
	for(int i=0;i<s.size();i++){
		if(s[i]!=k[i]){
			ans++;
		}
	}
	cout<<ans/2;
	return 0;
}