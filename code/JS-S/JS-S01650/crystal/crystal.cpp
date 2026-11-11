#include<bits/stdc++.h>
#define int long long
using namespace std;
long long a[500005];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n==1){
		cout<<1<<'\n';
		return 0;
	}
	sort(a+1,a+n+1);
	int l=n;
	long long ltot=0;
	for(;l>=1;l--){
		if(ltot+a[n]-a[l]>m){
            break;
		}
		ltot+=a[n]-a[l];
	}
	l=max(l,1LL);
	int ans=n-l+1;
	for(int i=n-1;i>=1;i--){
		if(l<i)
			ltot-=1LL*(i-l+1)*(a[i+1]-a[i]);
		else l=i,ltot=0;
        for(;l>=1;l--){
            if(ltot+a[i]-a[l]>m){
                break;
            }
            ltot+=a[i]-a[l];
        }
        l=max(l,1LL);
		long long now=0;
		ans=max(ans,i-l);
	}
	cout<<ans<<'\n';
	return 0;
}
