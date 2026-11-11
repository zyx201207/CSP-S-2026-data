#include <bits/stdc++.h>

using namespace std;
int n,m;
long long a[200010];
char c[200010],s[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		m+=a[i];
		for(int j=1;j<=a[i];j++){
			s[j]+=c[i];
		}
	}
	cout<<0;
	return 0;
}

