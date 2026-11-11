#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve(){
    int n;
    ll d;
    cin>>n>>d;
    vector<ll> x(n);
    for(int i=0;i<n;i++)cin>>x[i];
    vector<int> nxt(n),pre(n);
    for(int i=0,j=0;i<n;i++){
        j=max(j,i);
        while(j+1<n&&x[j+1]-x[i]<=d)j++;
        nxt[i]=j;
    }
    for(int i=n-1,j=n-1;~i;i--){
        j=min(j,i);
        while(j&&x[i]-x[j-1]<=d)j--;
        pre[i]=j;
    }
    ll ans=0;
    for(int u=0;u<n;u++){
        for(int v=u+1;v<n;v++){
            vector<int> p1,p2;
            p1.push_back(u),p2.push_back(v);
            while(p1.back()<v&&nxt[p1.back()]!=p1.back())p1.push_back(nxt[p1.back()]);
            if(p1.back()<v)continue;
            p1.back()=v;
            while(p2.back()>u&&pre[p2.back()]!=p2.back())p2.push_back(pre[p2.back()]);
            p2.back()=u;
            reverse(p2.begin(),p2.end());
            int fail=0,cnt=0;
            for(int i=0;i<p1.size();i++){
                if(p1[i]!=p2[i]){
                    if(p2[i]!=p1[i]-1)fail=1;
                    cnt++;
                }
            }
            if(!fail&&cnt==1)ans++;
        }
    }
    cout<<ans<<endl;
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int _,T;
    cin>>_>>T;
    while(T--)solve();
    return 0;
}