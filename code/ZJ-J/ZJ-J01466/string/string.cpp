#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+20;
ll n,s,sum,ans;
int a[N];
char c[N];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	int i=1,j=n;
	while(i<j&&s<sum/2) {
		if(a[i]>=a[j]) {
			a[i]-=a[j];
			s+=a[j];
			if(c[i]!=c[j]) {
				ans+=a[j];
			}
			j--;
		} else {
			a[j]-=a[i];
			s+=a[i];
			if(c[i]!=c[j]) {
				ans+=a[i];
			}
			i++;
		}
	}
    cout<<ans;
	return 0;
}
