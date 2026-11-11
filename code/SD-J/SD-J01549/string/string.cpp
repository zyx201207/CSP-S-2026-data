#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<char> s;
int n;
int ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char ch;
		cin>>a>>ch;
		while(a--) s.push_back(ch);
	}
	int len=s.size();
	for(int i=0;i<=len/2;i++){
		if(s[i]!=s[len-i-1]) ans++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

