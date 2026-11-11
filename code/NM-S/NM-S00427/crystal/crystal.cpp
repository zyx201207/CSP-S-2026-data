#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+100;
ll n,m;
ll a[N],b[N];
bool cmp(ll a,ll b){
	return a<b;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		b[i]=a[i]+b[i-1];
	}
	ll k=1,ans=0,q;
	for(int i=1;i<=n;i++){
		q=(i-k+1)*a[i]-b[i]+b[k-1];
		while(q>m){
			q-=a[i]-a[k];
			k++;
		}ans=max(ans,i-k+1);
	}cout<<ans;
    return 0;
}






