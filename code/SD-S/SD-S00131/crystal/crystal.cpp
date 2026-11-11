#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;
long long n,k;
long long a[N],b[N];
long long ans1,ans;

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin>>n>>k;
	long long maxx=0;
	for(int i=1; i<=n; i++) {
		cin>>b[i];
		maxx=max(maxx,b[i]);
	}
	sort(b+1,b+1+n);

	for(int m=1; m<=maxx; m++) {
		for(int j=1; j<=n; j++) {
			long long kk=k;
			ans1=0;
			for(int i=1; i<=n; i++) {
				a[i]=b[i];
			}
			for(int i=j; i<=n; i++) {
				while(a[i]<m&&kk>0) {
					a[i]++;
					kk--;
				}
				if(a[i]==m)ans1++;
			}
			ans=max(ans,ans1);
		}
	}
	cout<<ans;
	return 0;
}
