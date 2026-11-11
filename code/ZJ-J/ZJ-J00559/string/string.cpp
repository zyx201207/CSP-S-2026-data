#include<bits/stdc++.h>
using namespace std;
long long n,x,ans;
char c;
string s,t;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>x>>c;
		string s2=string(x,c);
		s+=s2;
	}
	long long l=s.size();
	for(int i=0; i<=l/2; i++)
		if(s[i]!=s[l-i-1])
			ans++;
	cout<<ans<<"\n";
	fclose(stdin);
	fclose(stdout);
	return 0;
}