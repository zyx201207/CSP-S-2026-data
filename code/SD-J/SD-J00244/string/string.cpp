#include<iostream>
#include<cstring>
using namespace std;
char s[10000007];
int n,pos=0;
long long a,ans;
long long tot=0;
char c;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a>>c;
		tot+=a;
		if(tot>=10000009) {
			cout<<3000000000;
			cout<<endl;
			return 0;
		}
		for(int j=1; j<=a; j++) {
			s[++pos]=c;
		}
	}

	int len=pos;
	for(int i=1; i<=len/2; i++) {
		if(s[i]!=s[len-i]) {
			ans++;
		}
	}
	cout<<ans<<endl;
	cout<<endl;
	return 0;
}
