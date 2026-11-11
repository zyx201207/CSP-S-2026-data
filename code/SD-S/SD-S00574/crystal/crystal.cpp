#include<bits/stdc++.h> 
#define int long long
using namespace std;
int n,m;int a[500500],b[500500],maxn=-(1ll<<62);
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int mq=a[1],c=1;
	for(int i=2;i<=n;i++){
		while((a[i]-mq)*(i-c)>m){
			maxn=max(maxn,i-c);
			m+=mq-a[c];c++;
		}
		m-=(a[i]-mq)*(i-c);mq=a[i];
	}maxn=max(maxn,n-c+1);
	cout<<maxn;
	return 0;
}
