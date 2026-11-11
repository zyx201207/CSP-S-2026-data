#include<bits/stdc++.h>
using namespace std;
string s;
int n,l,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++){
		int x;
		string c;
		cin>>x>>c;
		l+=x;
		for(int i = 1;i<=x;i++) s+=c;
	}
	for(int i = 0;i<l;i++){
		if(s[i]!=s[l-i-1]){
			s[l-i-1]=s[i];
			ans++;
		}
	}
	string r = s;
	reverse(r.begin(),r.end());
	if(r==s) cout<<ans;
	return 0;
}
