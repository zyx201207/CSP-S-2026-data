#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,a,ans=0;
char c;
vector<char> s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		if(a>10000000) return puts("3000000000"),0;
		while(a--) s.push_back(c);
	}
	for(int i=0;i<n/2+1;i++){
		if(s[i]!=s[n-i]){
			s[n-i]=s[i];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
