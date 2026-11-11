#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,ans=0,num;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int k;
		string a;
		cin>>k>>a;
		num+=k;
		for(int j=1;j<=k;j++){
			s+=a;
		}
	}
	for(int i=0;i<num/2;i++){
		if(s[i]!=s[num-i-1]){
			
			ans++;
			
		}
	}
	cout<<ans;
	return 0;
}