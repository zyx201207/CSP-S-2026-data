#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m,a[N];
ll ans;
bool flag=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]) flag=0;
	}
	if(flag){
        ll sum=a[2]-a[1],cnt=0;
        for(int i=2;i<=n;i++){
            cnt+=(i-1)*sum;
            if(m>=cnt) ans=i;
            else break;
        }
        cout<<ans<<'\n';
        //cerr<<ans<<'\n';
        return 0;
	}
	sort(a+1,a+1+n);
	for(int r=n;r>=1;r--){
            ll sum=0,cnt=0;
        for(int l=r;l>=1;l--){
            sum+=a[r]-a[l];
            if(sum<=m) cnt++;
            else break;
        }
        ans=max(ans,cnt);
	}
	cout<<ans<<'\n';
	//cerr<<ans<<'\n';
	return 0;
}
