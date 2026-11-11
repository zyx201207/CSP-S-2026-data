#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1000000];
long long MAX=-1;
void DFS(int i,long long now,long long cnt,long long sum) {
	if(sum>m) return;
	if(i>n) {
		if(sum<=m) MAX=max(MAX,cnt);
		return;
	}
	DFS(i+1,1,max(now,cnt),sum);
	for(int j=i+1; j<=n; j++) {
		DFS(i+1,now+1,max(now,cnt),sum+now*(a[j]-a[i]));
	}
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	DFS(1,1,1,0);
	cout<<MAX;
	return 0;
}