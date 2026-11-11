#include<bits/stdc++.h>
using namespace std;
int n,x,ans;string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	cin>>n;
	for(int i=1;i<=n;i++){
		int l;char c;
		cin>>l>>c;
		while(l--)s+=c;
	}
	for(int i=0;i<s.length();i++){
		if(s[i]!=s[s.length()-i]){
			s[s.length()-i]=s[i];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

