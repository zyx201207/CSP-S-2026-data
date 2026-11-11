#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,cnt,t,p,Max;
int a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		cnt+=a[i];
		p++;
		while(a[i]*p-cnt>m){
			cnt-=a[i-p+1];
			p--;
		}
		Max=max(Max,p);
	}
	cout<<Max; 
	return 0;
}
