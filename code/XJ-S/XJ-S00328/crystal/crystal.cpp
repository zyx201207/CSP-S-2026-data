#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,a[N],pre[N],m;
bool check(int len){
	for(int l=1;l+len-1<=n;l++){
		int r=l+len-1;
		int sum=pre[r]-pre[l-1];
		int maxn=a[r];
		if(sum+m>=maxn*len)	return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)	pre[i]=pre[i-1]+a[i];
	int l=0,r=N+10;
	while(l<r-1){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid;
		}
		else	r=mid;
	}
	cout<<l;
	return 0;
}
//rp++
//14:56
