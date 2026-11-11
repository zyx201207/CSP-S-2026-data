#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
ll a[N];
char c[N];
int vis[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	ll s=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		s+=a[i];
	}
	ll l=0,r=0;
	char l1=0,r1=0;
	ll ans=0;
	int cnt1=0,cnt2=n+1;
	for(int i=1;i<=n;i++){
		if(l<r){
			cnt1++;
			if(vis[cnt1]==1){
				break;
			}
			l+=a[cnt1];
			l1=c[cnt1];
			vis[cnt1]=1;
		}else if(l==r){
			cnt1++,cnt2--;
			if(vis[cnt1]==1||vis[cnt2]==1){
				break;
			}
			l+=a[cnt1];
			l1=c[cnt1];
			r+=a[cnt2];
			r1=c[cnt2];
			vis[cnt1]=1;
			vis[cnt2]=1;
		}else{
			cnt2--;
			if(vis[cnt2]==1){
				break;
			}
			r+=a[cnt2];
			r1=c[cnt2];	
			vis[cnt2]=1;
		}
		int flag=0;
		if(l1!=r1){
			flag=1;
		}
		if(flag)ans+=min(l,r);
		ll x=min(l,r);
		l-=x;
		r-=x;
	}
	cout<<ans<<endl;
	return 0;
}