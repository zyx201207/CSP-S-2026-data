#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define srccf ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define N 500007
#define ll long long

ll n,m;
ll a[N],c[N];
int find(int id){
	ll l=1,r=id-1,mid=(l+r)>>1;
	ll ans=0;
	while(l<r){
		ans++;if(ans>5) break;
//		cout<<l<<' '<<r<<' '<<mid<<endl;
		mid=(l+r)>>1;
//		if(r==mid) break;
		if((a[id]*(id-mid)-c[id-1]+c[mid-1])>m){
			l=mid+1;
		}else{
			r=mid;
		}
	}
//	printf(" %d %d\n",l,r);
	return l;
}
int main(){
	srccf;
	freopen("","r",stdin);
	freopen("","w",stdout);
	
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);//cin>>m;
	for(ll i=1;i<=n;i++){
		c[i]=a[i]+c[i-1];
	}
	ll ans=1;
	for(int i=1;i<=n;i++){
//		cout<<i<<endl;
		int fd=find(i);
		ans=max((ll)(i-fd+1),ans);
//		cout<<fd<<endl<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
//ci=ai-a1+...ai-ai-1
//ci+1=ai+1-ai
