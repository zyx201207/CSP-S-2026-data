#include<bits/stdc++.h>
using namespace std;
struct Node{
	long long x;
	char c;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans = 0;
	cin>>n;
	for(long long i = 1;i <= n;i ++) cin>>a[i].x>>a[i].c;
	long long l = 1,r = n,cnt;
	while(l < r){
		cnt = min(a[l].x,a[r].x);
		if(a[l].c != a[r].c) ans += cnt;
		a[l].x -= cnt;
		a[r].x -= cnt;
		if(a[l].x <= 0) l ++;
		if(a[r].x <= 0) r --;
	}
	cout<<ans;
	return 0;
}
