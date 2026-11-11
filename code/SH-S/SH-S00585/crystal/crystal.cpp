#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m;
ll a[N];
int f[N];
int ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
    ll p=m;
	for(int i=n;i>=1;i--){
		m=p;
		int r=i;
		int cnt=1;
		while(m>0){
			r--;
			if(r==0)break;
			ll it=a[i]-a[r];
			m-=it;
			if(m>=0){
				cnt++;
			}
			else{
				
				break;
			}
		}
		f[i]=cnt;
		ans=max(ans,f[i]);
	}
	cout<<ans<<endl;
    return 0;
}
