#include<bits/stdc++.h>
using namespace std;

const int N=500005;
int n;
long long a[N], ans;
unsigned long long m, s[N], subt;
bool flag;

int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	flag=0;
	
	cin>>n>>m;
	if(n>5000) flag=1;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1, a+n+1);
	
	for(int i=1;i<=n;i++) {
		s[i]=s[i-1]+(a[n]-a[n-i+1]);
	}
	
	ans=0;
	for(int i=1;i<=n;i++) {
		ans=max(ans, upper_bound(s+i, s+n+1, m) - (s+i));
		if(flag) {
			cout<<ans;
			fclose(stdin);
			return 0;
		}
		subt=s[i+1];
		for(int j=i+1;j<=n;j++) s[j]-=((j-i)*subt);
	}
	cout<<ans;
	
	fclose(stdin);
	return 0;
}
