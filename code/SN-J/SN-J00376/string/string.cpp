#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const ll maxn=2e5+10;
const ll inf=1e18+10;
int n;
struct intt{
	ll x;
	char c;
}a[maxn];
int l,r;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
		r+=a[i].x;
	}
	int ans=0;
	int lb=1,rb=n;
	while(l<=r&&lb<rb){
		int cnt;
		cnt=min(a[lb].x,a[rb].x);
		if(a[lb].c!=a[rb].c){
			ans+=cnt;
		}
//		cout<<"cnt:"<<cnt<<" l:"<<l<<" r:"<<r<<"\n";
		l+=cnt;
		r-=cnt;
		if(a[lb].x>a[rb].x){
			a[lb].x-=a[rb].x;
			rb--;
		}
		else if(a[lb].x<a[rb].x){
			a[rb].x-=a[lb].x;
			lb++;
		}
		else if(a[lb].x==a[rb].x){
			rb--;
			lb++;
		}
//		cout<<lb<<" "<<rb<<"\n";
	}
	cout<<ans;
	return 0;
}
