#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;

ll a[N],s[N];
ll n,m,ans;

ll ch(ll mid){
	ll cnt=0,sum=1;
	int ca[N];
	for(int i=1;i<mid;i++){
		ca[i]=a[mid]-a[i];
	}
	for(int i=mid-1;i>=1;i--){
		if(cnt+ca[i]>m)break;
		cnt+=ca[i];
		sum++;
	}
	return sum;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll l=0,r=n,mid;
	while(l<r){
		mid=(l+r)/2;
		int x=ch(mid);
		if(x>ans){
			l=mid;
			ans=x;
		}else{
			r=mid;
		}
	}
	cout<<ans;
	return 0;
} 