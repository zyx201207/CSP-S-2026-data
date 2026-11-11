#include<bits/stdc++.h>
using namespace std;
long long n;
string s = "";
long long len;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	while(n--){
		long long a;
		char c;
		cin>>a>>c;
		for(int i = 1;i <= a;i++){
			s += c;
		}
		len += a;
	}
	for(int i = 0;i < len/2;i++){
		if(s[i] != s[len-1-i]){
			s[len-1-i] = s[i];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
