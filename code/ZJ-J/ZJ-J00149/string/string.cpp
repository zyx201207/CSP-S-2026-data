#include<bits/stdc++.h>
#define int long long
using namespace std;
char c;int k,n,ans;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k>>c;
		s+=std::string(k,c);
	}
	for(int i=0,j=s.size()-1;i<j;i++,j--){
		if(s[i]!=s[j])ans++;
	}
	cout<<ans<<endl;
	return 0;
}

