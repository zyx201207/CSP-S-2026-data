#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],b[N],flag1,flag2,ans;
signed main() {
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) {
		cin>>a[i];
		if(a[i]!=i) {
			flag1=1;
		}
		if(i>2) {
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]) {
				flag2=1;
			}
		}
	}
	if(flag1==0) {
		for(int i=1;i<=1e9;++i) {
			ans+=i;
			if(ans>m) {
				cout<<i-1;
				return 0;
			}
		}
	}
	else if(flag2==0) {
		for(int i=1;i<=1e9;i+=a[2]-a[1]) {
			ans+=i;
			if(ans>m) {
				cout<<i-1;
				return 0;
			}
		}
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i) {
		b[i]=b[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	int i=1,j=n;
	while(b[j]-b[i]-(i-1)*(a[j]-a[i])>m) {
		if(b[j-1]-b[i]-(i-1)*(a[j-1]-a[i])<b[j]-b[i+1]-(i)*(a[j]-a[i+1])) {
			j--;
		}
		else if(b[j-1]-b[i]-(i-1)*(a[j-1]-a[i])>b[j]-b[i+1]-(i)*(a[j]-a[i+1])) {
			i++;
		}
		else {		
			if(b[j-1]-b[j-2]-(j-2)*(a[j-1]-a[j-2])<b[i+2]-b[i+1]-(i+1)*(b[i+2]-b[i+1])) {
				j--;
			}
			else if(b[j-1]-b[j-2]-(j-2)*(a[j-1]-a[j-2])<b[i+2]-b[i+1]-(i+1)*(b[i+2]-b[i+1])) {
				i++;
			}
			else {
				if(b[j-1]-b[i+1]-(i+1)*(b[j-1]-b[i+1])>m) {
					i++;j--;
				}
				else cout<<j-i;
			}
		}
	}
	cout<<j-i+1;
	return 0;
}
