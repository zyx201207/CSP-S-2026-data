#include<bits/stdc++.h>
using namespace std;
int t,ans,slen;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		char c;
		cin>>n>>c;
		for(int i=1;i<=n;i++){
			s+=c;
			slen++;
		}
	}for(int i=0,j=slen-1;i!=j;i++,j--){
		if(s[i]!=s[j]){
			ans++;
		}
	}cout<<ans;
	return 0;
}
