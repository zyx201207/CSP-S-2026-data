#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ifstream fin("crystal.in");
ofstream fout("crystal.out");

void commit(ll ans){
    fout<<ans<<endl;
}

int main(){
    ll n,m;
    fin>>n>>m;
    vector<ll> ori(n);
    vector<ll> pref(n);
    for(ll i=0;i<n;i++){
        fin>>ori[i];
    }
    sort(ori.begin(),ori.end());
    pref[0]=0;
    for(ll i=1;i<n;i++){
        pref[i]=(ori[i]-ori[i-1])*i+pref[i-1];
    }
    ll ans=0;
    ll pb=0,pe=0;
    while(pe<n){
        while(pe<n&&((pref[pe]-pref[pb])<=m)){
            pe++;
        }
        if((pe==n)){
            if(pref[pe-1]-pref[pb]<=m){
                ans=max(ans,pe-pb+1);
            }
            commit(ans);
            return 0;
        }
        ans=max(ans,pe-pb);
        while((pb<pe)&&((pref[pe]-pref[pb])>m)){
            pb++;
        }
        ans=max(ans,pe-pb+1);
    }
    commit(ans);
}
