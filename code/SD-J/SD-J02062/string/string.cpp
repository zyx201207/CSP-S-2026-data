#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int t,ans;
char c;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>t;
	while(t--){
		int x;
		cin>>x>>c;
		for(int i=1;i<=x;i++){
			s+=c;
		}
	}	
	int l=s.size();
	for(int i=0,j=l-1;i<=j;i++,j--){
		if(s[i]!=s[j]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
