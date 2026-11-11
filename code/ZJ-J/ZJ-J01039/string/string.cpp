#include<bits/stdc++.h>
using namespace std;
string s;
int n,a,ans;
char c;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s+=c;
		}
	}
	for(int i=0;i<(int)s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i]) ++ans;
	}
	cout<<ans<<endl;
	return 0;
}