#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define rrep(i,r,l) for(int i=r;i>=l;i--)
#define fi first
#define sc second
#define pb push_back
#define pq priority_queue
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m;
ll A[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	rep(i,1,n){
		cin>>A[i];
	}
	sort(A+1,A+n+1);
	int l=1;
	ll sum=0;
	int ans=0;
	rep(i,1,n){
		sum+=(i-l)*(A[i]-A[i-1]);
		while(sum>m){
			sum-=A[i]-A[l];
			l++;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
