#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll ans=0;
string s;
//ll pre[200005][28],sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	s=' '+s;
	for(int i=1;i<=n;i++){
		ll a;
		char c;
		cin>>a>>c;
		while(a--){
			s+=c;
		}
//		sum+=s;
//		pre[i][c-'a'+1]+=s;
//		for(int j=1;j<=26;j++){
//			pre[i][j]=pre[i-1][j];
//		}
	}
	ll len=(s.size())/2;
	for(int i=1;i<=len;i++){
		if(s[i]!=s[s.size()-i]){
			ans++;
		}
	}
	cout<<ans;
//	sum=(sum+1)/2;
//	for(int i=1;i<=n;i++){
//		
//	}
	return 0;
}
