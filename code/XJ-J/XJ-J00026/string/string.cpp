#include<bits/stdc++.h>
using namespace std;
int n,b[30];
char s[3],ss[3];
int main(){
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		long long a;
		char c;
		cin>>a>>c;
		b[c-'a'+1]+=1;
	}
	for(int i=1;i<=26;++i){
		if(b[i]==n){cout<<0;return 0;}
		else cout<<0;
	}
	return 0;
}
