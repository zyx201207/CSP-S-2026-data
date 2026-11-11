#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0;
	string s;
	cin>>n;
	while(n--){
		int a;
		string s1;
		cin>>a>>s1;
		for(int i = 1;i<=a;i++){
			s+=s1;
		} 
	}
	for(int i = 0;i<s.size();i++){
		if(s[i]!=s[i+1]) ans++;
	}
	cout<<ans-1;
	return 0;
}

