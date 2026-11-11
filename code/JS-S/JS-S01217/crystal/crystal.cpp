#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n;
    ull m;
    cin >> n >> m;
    vector<ll> power;
    bool isspecial = true;
    ll in;
    for(ll i=0;i<n;i++){
        cin >> in;
        power.push_back(in);
    }
    sort(power.begin(),power.end());
    ll d = power[1]-power[0];
    for(int i=2;i<n;i++){
        if(power[i]-power[i-1]!=d) isspecial=false;
    }
    ull m1 = m;
    ull num;
    ull ans=1;
    if(isspecial==true){
        num=d;
        for(int i=n-1;i>=0;i--){
            if(m1<num){
                cout << ans << endl;
                return 0;
            }
            m1-=num;
            num+=d;
            ans++;
        }
        cout << n << endl;
        return 0;
    }




    d=0;
    ull cur = 1;
    for(ll i=n-1;i>=0;i--){
        cur = 1;
        m1 = m;
        for(ll j=i-1;j>=0;j--){
            d = power[i]-power[j];
            if(m1<d) continue;
            else{
                m1-=d;
                cur++;
            }
        }
        ans=max(ans,cur);
    }
    cout << ans << endl;
    return 0;
}
