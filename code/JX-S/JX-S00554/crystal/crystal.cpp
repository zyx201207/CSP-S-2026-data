#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll a[N],ma=-1e18,mi=1e18,s[N];
map<ll,int> id;

int n,m;
bool ck(int len){
    for(int i=1;i<=n-len+1;i++){
		int k=i+len-1;
		ll v=s[k]-s[i-1],b=len*a[k];
		if(v+m>=b)return 1;
	}return 0;
}
int main(){
	freopen("crysta.in","r",stdin);
	freopen("crysta.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    int ans=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ma=max(ma,a[i]);
        mi=min(mi,a[i]);
        id[a[i]]++;
        ans=max(id[a[i]],ans);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)s[i]+=s[i-1]+a[i];
    int l=1,r=n;
    while(l<r){
        int mid=(l+r+1)>>1;
        if(ck(mid)){
			l=mid;
			ans=max(ans,mid);
		}else r=mid-1;
    }
    cout<<ans<<'\n';
    return 0;
}
