#include<bits/stdc++.h>
using namespace std;
long long n,a,l,ans;
char c;
string s="",s1,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
    	cin>>a>>c;
    	for(long long j=1;j<=a;j++) s+=c;
	}
	l=s.size();
	s1=s.substr(0,l/2);
	if(l%2) s2=s.substr(l/2+1,l/2);
	else s2=s.substr(l/2,l/2);
	reverse(s2.begin(),s2.end());
	for(long long i=0;i<s1.size();i++){
		if(s1[i]!=s2[i]) ans++;
	}
	cout<<ans;
	return 0;
}
