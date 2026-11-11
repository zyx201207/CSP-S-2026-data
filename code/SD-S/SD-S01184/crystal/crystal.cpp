#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005]; 
int q[500005],head,tail;
int ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int sum=0;
	for(int i=1;i<=n;i++){
		if(head<tail&&q[tail]<a[i]){
			sum+=(tail-head)*(a[i]-q[tail]);
		}
		q[++tail]=a[i];
		while(head<tail&&sum>m){
			sum-=(a[i]-q[++head]);
		}
		ans=max(tail-head,ans);
	}
	cout<<ans;
	return 0;
} 
//crystal.out crystal.ans
