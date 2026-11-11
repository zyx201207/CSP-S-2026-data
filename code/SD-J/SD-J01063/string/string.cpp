#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL n,ans,sum;
string s = "";

void hui(string s){
	int len = s.size();
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1]){
			ans++;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(LL i=1;i<=n;i++){
		char c;
		LL k;
		cin>>k>>c;
		s.insert(s.end(),k,c);
	}
	hui(s);
	cout<<ans;
	return 0;
}

