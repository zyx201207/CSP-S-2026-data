#include<bits/stdc++.h>
using namespace std;
string s,k;
int n,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a=0;
		cin>>a;
		cin>>k;
		for(int i=1;i<=a;i++)  s+=k;
	}
	if(s.size()%1){
		for(int i=0;i<s.size()/2-1;i++){
			if(s[i]!=s[n-i]) ans++; 
		}
	}else{
		for(int i=0;i<s.size()/2;i++){
			if(s[i]!=s[n-i]) ans++; 
		}
	}
	cout<<ans;
	return 0;
}