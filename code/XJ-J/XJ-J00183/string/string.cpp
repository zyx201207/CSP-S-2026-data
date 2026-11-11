#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000000005;
int n,x,ans=0;
char c;
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x>>c;
		for(int i=0;i<x;i++){
			s+=c;
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]!=s[s.size()-1-i]){
			ans++;
		}
		if(i==s.size()-1-i){
			break;
		}
	}
	cout<<ans;
	return 0;
}

