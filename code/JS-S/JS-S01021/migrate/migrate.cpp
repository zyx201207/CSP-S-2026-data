#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c;

void solve(){
    ll n,d;
    cin>>n>>d;
    vector<ll> a(n);
    for(int i=0;i<n;++i) cin>>a[i];

    if(n==1){
        cout<<0<<endl;
        return ;
    }

    if(c==11||c==12){
        ll cha=a[1]-a[0];
        cha=d/cha;
        cha+=cha;
        --cha;
        if(cha<=1) cout<<0<<endl;
        else if(cha>n) cout<<0<<endl;
        else cout<<n-cha<<endl;
        return ;
    }
    if(c==13||c==14){
        ll ans=0;
        vector<int> p(n+3);
        for(int i=0;i<n;++i){
            int k=lower_bound(a.begin(),a.end(),a[i]-d)-a.begin();
            int k1=upper_bound(a.begin(),a.end(),a[k-1]+d)-a.begin();
            int k2=upper_bound(a.begin(),a.end(),a[k]+d)-a.begin();
            ans+=max((ll)0,(ll)k2-k1+1);
        }
        cout<<ans<<endl;
        return ;
    }

    vector<int> p(n+3);
    for(int i=0;i<n;++i){
        int k=lower_bound(a.begin(),a.end(),a[i]-d)-a.begin();
        p[i]=k;
    }

    ll ans=0;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            vector<ll> sum(n);
            sum[i]=1;

            for(int k=i+1;k<=j;++k){
                int x=sum[k-1];
                if(max(p[k]-1,i-1)) x-=sum[max(p[k]-1,i-1)];
                sum[k]=sum[k-1]+x;

            }
            if(sum[j]-sum[j-1]==2) ++ans;
        }
    }

    cout<<ans<<endl;
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int t;
    cin>>c>>t;
    while(t--) solve();
    return 0;
}