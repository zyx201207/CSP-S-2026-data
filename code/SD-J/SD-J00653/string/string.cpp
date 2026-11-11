#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int N=1e6+10;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=1,ans=0,l=0;
	cin>>n;
	string st;
	for(int i=1;i<=n;++i){
		int q;
		char c;
		cin>>q>>c;
		for(int j=1;j<=q;++j,++cnt)st.push_back(c);
	}
	for(int i=0;i<st.size()/2;++i){
		if(st[i]==st[st.size()-i])continue;
		ans++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
