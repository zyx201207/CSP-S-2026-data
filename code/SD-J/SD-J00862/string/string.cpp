#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w".stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	string s;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int a;string b;
		cin>>a>>b;
		for(int j=0;j<a;j++)s+=b; 
	}
	int l=0,r=s.size()-1,ans=0;
	while(r>l){
		if(s[r]!=s[l]){
			s[l]=s[r];
			ans++;
		}
		l++;r--;
	}
	cout<<ans;
	return 0; 
} 
