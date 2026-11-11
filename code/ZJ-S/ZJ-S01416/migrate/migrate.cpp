#include<bits/stdc++.h>
using namespace std;
using LL=long long;
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
const int N=2e6;
LL a[N];
int lower(int L,int R,int x){
	if(L==R)return L;
	int mid=(L+R)>>1;
	if(a[mid]<x)return lower(mid+1,R,x);
	return lower(L,mid,x);
}
int upper(int L,int R,int x){
	if(L==R)return L;
	int mid=(L+R)>>1;
	if(a[mid]<=x)return upper(mid+1,R,x);
	return upper(L,mid,x);
}
void solve(){
	LL n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	LL ans=0;
	for(int l=1,r=1;r<=n;){
		if(a[r]-a[l]<=d){
			++r;
			continue;
		}
		while(a[r]-a[l]>=d*2)++l;
		int i=upper(l,r,a[l]+d)-1;
		int j=lower(l,r,a[r]-d);
		if(i-j+1==2)ans++;
		if(i-j+1>2)l++;
		else r++;
	}
	cout<<ans<<endl;
	return;
}
int main(){
	fast;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)solve();
	return 0;
}
