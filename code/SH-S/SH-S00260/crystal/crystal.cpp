#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m,a[N],sum[N];
bool check(int x,int c){
	return 1ll*a[x]*(x-c+1)-(sum[x]-sum[c-1])<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int L=1,R=i-1;
		while(L<=R){
			int mid=(L+R)/2;
			if(check(i,mid)) R=mid-1,ans=max(ans,i-mid+1);
			else L=mid+1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
