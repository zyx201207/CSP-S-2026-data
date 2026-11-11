#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;

    vector<ll> a(n+3);
    for(int i=0;i<n;++i) cin>>a[i];

    long long ans=0;
    vector<bool> b(n+3,1);
    for(int i=31;i>=0;--i){
        int cnt=0;
        vector<int> p;
        for(int j=0;j<n;++j){
            if(!b[j]) continue;
            if((a[j]|((ll)1<<i))>a[j]){
                p.push_back(j);
            }else ++cnt;
        }

        if(cnt>=m){
            ans+=((ll)1<<i);
            for(int j=0;j<(int)p.size();++j){
                b[p[j]]=0;
            }
        }
    }

    cout<<ans<<endl;
    return 0;
}