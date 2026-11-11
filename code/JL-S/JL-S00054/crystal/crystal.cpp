#include <bits/stdc++.h>
using namespace std;
//mt19937_64 rnd(time(0));
long long n,m;
long long a[500005];
long long ans;
long long last;
long long sum;
queue<long long> q;
long long siz;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	last=a[1];
	for (int i=1;i<=n;i++){
		sum+=(a[i]-last)*siz;
		siz++;
		q.push(a[i]);
		while (!q.empty() && sum>m){
			long long xz=q.front();
			q.pop();
			siz--;
			sum-=(a[i]-xz);
		}
		ans=max(ans,siz);
		last=a[i];
	}
	cout << ans;
	return 0;
}