#include <bits/stdc++.h>
using namespace std;
long long a[500005],ans=0,n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)a[i]+=a[i-1];
	int last=1;
	for(long long i=2;i<=n;i++){
		for(long long j=last;j<i;j++){
			if((a[i]-a[i-1])*(i-j)-(a[i-1]-a[j-1])<=m){
				ans=max(ans,i-j+1);
				last=j;
				break;
			}
		}
	}
	cout << ans;
	return 0;
} 
//AC!
/*
Can I get the second prize?
(Thinking....)
No commanda.
*/
