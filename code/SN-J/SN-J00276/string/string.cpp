#include <bits/stdc++.h>
using namespace std;
int n;
struct io{
	long long a;
	char c;
};
io ar[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	cin>>n;
	long long cun=0;
	for(int i=1;i<=n;i++){
		cin>>ar[i].a>>ar[i].c;
		for(int j=0;j<ar[i].a;j++){
			s+=ar[i].c;
		}
	}
	long long ans=0;
	for(int i=0;i<s.size()/2;i++){
		if(s[i]==s[s.size()-i-1]) continue;
		else ans++;
	}
	cout<<ans;
	return 0;
} 
