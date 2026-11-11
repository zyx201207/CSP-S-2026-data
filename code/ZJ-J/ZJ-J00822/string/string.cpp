#include <bits/stdc++.h>
using namespace std;
const long long inf=1000005;
long long ans;
int n;
vector<char>s;
int t;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int m;
		char x;
		cin>>m>>x;
		for(int j=0;j<m;j++){
			s.push_back(x);
		}
		t+=m;
	}
	for(long long i=0;i<t;i++){
		if(s[i]!=s[t-i-1]){
			ans++;
			s[t-i-1]=s[i];
		}
	}
	cout<<ans;
	return 0;
}