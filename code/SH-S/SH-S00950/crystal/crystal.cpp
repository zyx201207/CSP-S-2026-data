#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m;
ll a[N];
ll k,cnt;

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n>=3&&a[3]-a[2]==a[2]-a[1]&&a[n]-a[n-1]==a[2]-a[1]) {
		k=a[2]-a[1];
		while(m>=k&&cnt<n-1) {
			m-=k;
			k+=(a[2]-a[1]);
			cnt++;
		}
		cout<<cnt+1;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
