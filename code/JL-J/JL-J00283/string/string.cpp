#include<bits/stdc++.h>
using namespace std;
string s,s1,s2;
long long n,ans,ss;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		for(long long j=1;j<=a;j++){
			s+=c;
			ss++;
		}
	}
	for(long long i=0;i<ss/2;i++){
		s1+=s[i];
	}
	for(long long i=ss-1;i>=(ss+1)/2;i--){
		s2+=s[i];
	}
	for(long long i=0;i<ss/2;i++){
		if(s1[i]!=s2[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
