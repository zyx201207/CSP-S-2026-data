#include<bits/stdc++.h>
using namespace std;
constexpr int MAXN=2e5+5;
unsigned long long n,a[MAXN],sum,lr[MAXN],rr[MAXN],lc[MAXN],rc[MAXN],ll,rl;
char c[MAXN];
unsigned long long ans;
void check(){
    for(int i=1;i<=ll;i++){
        auto ptr=lower_bound(rr+1,rr+1+rl,lr[i]);
        for(;;ptr++){
            int idx=ptr-rr;
            cerr<<idx<<'\n';
            int l1=lr[i-1]+1,l2=rr[idx-1]+1,r1=lr[i],r2=rr[idx];
            cerr<<l1<<' '<<l2<<' '<<r1<<' '<<r2<<'\n';
            if(l1>r2) break;
            if(idx>rl) break;
            if(rc[idx]==lc[i]) continue;
            if(l1<=l2&&r1<=r2){
                ans+=l2-r1+1;
            }else if(l2<=l1&&r2<=r1){
                ans+=r2-l1+1;
            }else if(l1<=l2&&r2<=r1){
                ans+=r2-l2+1;
            }else if(l2<=l1&&r1<=r2){
                ans+=r1-l1+1;
            }
        }
    }
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i],sum+=a[i],cerr<<sum<<' ';
	for(int i=1;i<=n;i++){
        lr[i]=min(sum>>1,a[i]+lr[i-1]);
        lc[i]=c[i];
        if((sum>>1)<=a[i]+lr[i-1]){
            ll=i;
            break;
        }
	}
	for(int i=1;i<=n;i++){
        rr[i]=min(sum>>1,a[n+1-i]+rr[i-1]);
        rc[i]=c[n+1-i];
        if((sum>>1)<=a[n+1-i]+rr[i-1]){
            rl=i;
            break;
        }
	}
    check();
    cout<<ans;
	return 0;
}
