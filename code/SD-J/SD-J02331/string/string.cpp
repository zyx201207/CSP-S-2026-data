#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
string s;ll a,ans=0;ll len=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);

	int n;cin>>n;char c;
	for(int i=1;i<=n;++i){
		cin>>a>>c;
		for(int j=1;j<=a;++j){
			s+=c;
		}
		len+=a;
	}
//	cout<<len<<' ';
//	for(int i=0;i<len;++i)cout<<s[i];cout<<"\n";
	for(int i=0;i<(len+1)/2;++i){
		if(s[i]!=s[len-1-i])ans++;//!!
	}
	cout<<ans;
	return 0;
}
// aaaaa
