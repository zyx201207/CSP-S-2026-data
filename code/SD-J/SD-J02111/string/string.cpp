#include<bits/stdc++.h>
using namespace std;
long long n,ans;
string s1,s2,s;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int cnt=0;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		cnt+=a;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	for(int i=0;i<cnt/2;i++){
		s1+=s[i];
	}
	for(int i=cnt;i>cnt/2;i--){
		s2+=s[i-1];
	}
	for(int i=0;i<=cnt/2-1;i++){
		if(s1[i]!=s2[i]) ans++;
	}
	cout<<ans;
	return 0;
}
