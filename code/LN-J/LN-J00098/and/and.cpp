#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long ll;
void o_x(const auto & v0){
    for (auto x0 : v0){
        cout<<x0<<' ';
    }
    return;
}
void fen(ll x0,vector<char> &v0){
    for (int i=5;i>=0;i--){
        v0[i]='0';
        ll m=(1<<i);
        if (x0 & m){
            v0[i]='1';
            x0&=(m-1);
        }
    }

}

int n,m;
vector <bool> jug(n,0);
int main(){
    cin>>n>>m;
    vector <char> v[N];
    vector <ll> a;
    a.reserve(n);
    for (int i=0;i<n;i++){
        v[i].resize(30);
        ll x=0;
        cin>>x;
        a.emplace_back(x);
        fen(x,v[i]);
        jug[i]=1;
        o_x(v[i]);
    }
    o_x(a);
    int rest=n;
    for (int i=30;i>=0;i--){
        int t=0;
        if (rest<=m) break;
        for (int j=0;j<n;j++){
            if (jug[j] && v[j][i]=='1') t++;
        }
        if (t>=m){
            for (int j=0;j<n;j++){
                if (rest >=m && jug[j] && v[j][i]=='0'){
                    jug[j]=0;
                    rest--;
                    if (rest==2) break;
                }
            }
        }
    }
    o_x(jug);
    ll p=0;
    ll ans=(2<<31)-1;
    int now_x=0;
    for (int i=0;i<n;i++){
        if (now_x==m) break;
        if (jug[i]==1){
            p=a[i];
            ans &=p;
            now_x++;
        }
    }
    cout<<ans;
    return 0;
}
