#include<bits/stdc++.h>
using namespace std;
string s="";
long long len,cnt;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	while(n--){
		int a;
		char c;
		cin>>a>>c;
		len+=a;
		for(int i=0;i<a;i++) s+=c;
	}
	string S=s;
	reverse(s.begin(),s.end());
	for(int i=0;i<len/2;i++){
		if(S[i]!=s[i]) cnt++;
	}
	cout<<cnt;
	return 0;
}
