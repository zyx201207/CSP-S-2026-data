#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,m,a[N],maxx=-1e9,cnt=1;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long cha=a[3]-a[2];
	while(1) {
		if(m<=0) {
			break;
		}
		m-=cha;
		cha+=cha;
		cnt++;
	}
	cout<<cnt;
	return 0;
}
