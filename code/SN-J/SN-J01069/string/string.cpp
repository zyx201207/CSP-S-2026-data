#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		char c;
		cin>>m>>c;
		for(int i=1;i<=m;i++) s+=c;
	}
	int len=s.size();
	for(int i=0;i<len/2;i++) if(s[i]!=s[len-1-i]) ans++;
	cout<<ans;
	return 0;
} 
