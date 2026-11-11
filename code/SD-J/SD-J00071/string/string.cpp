#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
string s="";
long long len;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int f;
		char g;
		cin>>f>>g;
		s=s+string(f,g);
	}
	len=s.length();
	s=' '+s;
	if(len%2==1){
		for(long long i=len/2+1,j=len/2+1;i<=len&&j>=1;i++,j--){
			if(s[i]!=s[j]) ++ans;
		}
		cout<<ans;
	}
	else{
		for(long long i=len/2+1,j=len/2;i<=len&&j>=1;i++,j--){
			if(s[i]!=s[j]) ++ans;
		}
		cout<<ans;
	}
	return 0;
}

