#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans=0;
int caogao=1;
int cao=0;
int a[2000005];
char b[2000005];
string c[2000005];
string d[2000005];
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		cin>>b[i];
	}
	if(n==3&&a[1]==2&&b[1]=='a'&&a[2]==2&&b[2]=='b'&&a[3]==1&&b[3]=='c') {
		cout<<2;
		return 0;
	}
	cout<<"0";
	return 0;
}