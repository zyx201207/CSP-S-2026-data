#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n,a,ans=0;
string s,s1,s2;
char c;
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	cout<<s<<"\n";
	n=s.size();
	for(int i=0;i<n/2;i++){
		s1+=s[i];
	}
	for(int i=n/2+1;i<n;i++){
		s2+=s[i];
	}
	cout<<s1<<" "<<s2<<"\n";
	reverse(s2.begin(),s2.end());
	for(ll i=0;i<n/2;i++){
		if(s2[i]!=s1[i]) ans++;
	}
	cout<<ans;
	return 0;
}
