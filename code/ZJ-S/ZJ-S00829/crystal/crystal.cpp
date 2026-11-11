#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=500010;
ll a[MAXN],n,m,l,r,cnt,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	l=0;r=0;cnt=a[0];
	while(r<n){
		while(a[r]*(r-l+1)-cnt>m){
			cnt-=a[l];
			l++;
		}
		ans=max(ans,r-l+1);
		r++;
		cnt+=a[r];
	}
	cout<<ans;
	return 0;
}