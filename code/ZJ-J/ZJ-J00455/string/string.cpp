#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
struct node{
	int x;
	char y;
}a[N];
int sum=0;
int q[N],h[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int l=1,r=0;
	int ll=1,rr=n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		r+=a[i].x;
		q[i]=q[i-1]+a[i].x;
	}
//	for(int i=n;i>=1;i--){
//		h[i]=h[i+1]+a[i].x;
//	}
	int ans=0;
	while(ll<=rr&&l<=r){
		if(a[ll].y==a[rr].y){
			int x=min(q[ll]-l+1,r-q[rr-1]);
			l+=x,r-=x;
			if(l>q[ll])ll++;
			if(r<=q[rr-1])rr--;
		}
		else{
			int x=min(q[ll]-l+1,r-q[rr-1]);
//			cout<<ll<<" "<<rr<<" "<<l<<" "<<r<<" "<<x<<"\n";
			ans+=x;
			l+=x,r-=x;
			if(l>q[ll])ll++;
			if(r<=q[rr-1])rr--;
		}
	}
	cout<<ans;
	return 0;
}
