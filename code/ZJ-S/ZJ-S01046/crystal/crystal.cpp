#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
inline ll read(){
    int c,w=1;
    ll ret=0;
    while((c=getchar())>'9'||c<'0') w=(c=='-'?-1:1);
    ret=c-48;
    while((c=getchar())<='9'&&c>='0') ret=ret*10+c-48;
    return w*ret;
}

int const maxn=5e5+5;
ll const inf=1e12+5;

int n,ans;
ll m;
ll a[maxn];
ll s[maxn];

bool check(ll L,ll R,ll x){
//    if(x*(R-L+1)<=m+(s[R]-s[L-1])) return 1;
//    return 0;
	ll del=R-L+1;
	ll cnt=-s[R]+x*del+s[L-1];
	//for(int i=R;i>=L;i--) cnt+=x;
	//cnt-=s[R]-s[L];
	return cnt<=m;

}

int sol(int x){
    int l=1,r=x,mid;
    while(l<=r){
        mid=l+r>>1;
        if(check(mid,x,a[x])) r=mid-1;
        else l=mid+1;
    }
//	for(int i=x;i>=1;i--){
//		if(check(i,x,a[x])==0){
//			l=i+1;
//			break;
//		}
//	}
    ans=max(ans,x-l+1);
    return l;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        //cin>>a[i];
        //s[i]=s[i-1]+a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++){
        sol(i);
    }
    cout<<ans;


    return 0;
}