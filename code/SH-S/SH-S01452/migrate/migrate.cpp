#include <bits/stdc++.h>
using namespace std;

int n;
long long m;
long long l[500005];

int max(int x){
	long long count=0;
	int i=x;
	while(count+l[x]-l[i]<=m){
		count+=l[x]-l[i];
		i--;
		if(i==0) break;
	}
	return x-i;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> l[i];
	sort(l+1,l+n+1);
	int cnt=1;
	for(int i=1;i<=n;i++){
		if(max(i)>cnt) cnt=max(i);
	}
	cout << cnt << "\n";
	return 0;
}
