#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll a,cnt=0;
string s="",c; 
bool huiwen(string ss){
	for(int i=0,j=ss.size();i<=ss.size()/2;i++,j--){
		if(ss[i]!=ss[j]) return 0;
	}
	return 1;
}
void gg(int x){
	if(huiwen(s)){
		return;
	}
	cnt++;
	for(int i=0;i<26;i++){
		if(x<s.size()){
			s[x]='a'+i;
			gg(x+1);
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		for(int j=0;j<a;j++){
			s+=c;
		}
	}
	gg(0);
	cout<<cnt<<'\n';
	return 0;
}

