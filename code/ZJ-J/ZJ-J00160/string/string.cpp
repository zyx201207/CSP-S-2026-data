#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],l=1,ans;
char b[200005],c[1000000001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		for(int j=1;j<=a[i];j++){
			c[l]=b[i];
			l++;
		}
	}
	l--;
	for(int i=1;i<=l/2+1;i++){
		if(c[i]!=c[l-i+1])
		ans++;
	}
	cout<<ans;
	return 0;
}