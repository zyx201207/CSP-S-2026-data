#include<bits/stdc++.h>
using namespace std;
int n,a;
long long l,ans;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a>>c;
		l+=a;
		for (int j = 1;j<=a;j++) s+=c;
	}
	for (int i = 0;i<l/2;i++){
		if (s[i]!=s[l-1-i]) ans++;
	}
	cout<<ans;
	return 0;
}

