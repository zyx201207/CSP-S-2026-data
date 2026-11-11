#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
pair<int ,char> a[N];
int n;
bool f=0;
long long sum=0,cnt;
string s=" ";
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >>n;
	for(int i=1; i<=n; i++) {
		cin >> a[i].first >> a[i].second;
		sum+=a[i].first;
		for(int j=1; j<=a[i].first; j++) {
			s+=a[i].second;
		}
		if(a[i].second!=a[i-1].second&&i!=1) f=1;
	}
	if(f==0) {
		cout << 0;
		return 0;
	}
	for(int i=1,j=sum; i<=sum/2&&j>=sum/2; i++,j--) {
		if(s[i]!=s[j]) {
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}
