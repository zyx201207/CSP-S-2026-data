#include<bits/stdc++.h>
using namespace std;
const long long maxn=1e5+5;
long long n,m,cnt=0,x=0;
long long a[maxn];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int temp=0;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1; i<=n-1; i++) {
		if(a[i]<a[i+1]&&cnt<m) {
			for(int j=1; j<=i; j++) {
				cnt+=a[i+1]-a[j];
				a[j]=a[i+1];
			}
		}
		if(cnt>=m) break;
	}
	for(int i=1; i<=n; i++) {
		if(a[i]==a[1]) {
			x++;
		} else {
			cout<<x;
			return 0;
		}
	}
	cout<<x;
	return 0;
}