#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		int a;
		cin>>a;
		char c;
		cin>>c;
		while(a--){
			s+=c;
		}
	}
	for(int i=0;i<ceil(s.length()/2);i++){
		if(s[i]!=s[s.length()-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}

