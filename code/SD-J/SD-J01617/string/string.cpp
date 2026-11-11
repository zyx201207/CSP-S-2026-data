#include<bits/stdc++.h>//68
#define ll long long
using namespace std;
ll n,a,ans;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a>>c;
		while(a--)s+=c;}
	for(int i=0;i<s.size();i++){
		if(s[i]!=s[s.size()-1-i])ans++;}
	cout<<ans/2;
	return 0;}
