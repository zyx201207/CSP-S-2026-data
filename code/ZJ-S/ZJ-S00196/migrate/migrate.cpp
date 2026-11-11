#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int C,T;
    cin>>C>>T;
    while(T--) {
        int n;
        ll d;
        cin>>n>>d;
        vector<ll> x(n);
        for(ll& i:x) cin>>i;
        if(n==1) {
            cout<<"0\n";
            continue;
        }
        ll dif=x[1]-x[0];
        bool A=true;;
        for(int i=2;i<n;++i) {
            if(x[i]-x[i-1]!=dif) {
                A=false;
                break;
            }
        }
        if(A) {
            if(d>=dif*2) cout<<max(0ll,n-(d/dif)*2+1)<<'\n';
            else cout<<"0\n";
            continue;
        }
        vector<int> dis(n+1);
        vector<int> cnt(n+1);
        ll res=0;
        for(int i=0;i<n;++i) {
            dis[i]=0;
            cnt[i]=1;
            int l=i;
            for(int j=i+1;j<n;++j) {
                while(x[j]-x[l]>d) ++l;
                if(l==j) break;
                dis[j]=dis[l]+1;
                cnt[j]=cnt[l];
                if(l+1<j&&dis[l+1]==dis[l]) cnt[j]+=cnt[l+1];
                if(l+2<j&&dis[l+2]==dis[l]) cnt[j]+=cnt[l+2];
                if(cnt[j]>3) cnt[j]=3;

                if(cnt[j]==2) {
                    ++res;
                    // cerr<<i<<' '<<l<<' '<<j<<'\n';                
                }
            }
        }
        cout<<res<<'\n';
    }
}