#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,m;
    cin >> n >> m;
    vector<long long> t;
    for(int i=1;i<=n;i++){
        long long x;
        cin >> x;
        t.push_back(x);
    }
    long long ans=0;
    bool k=0;
    for(int j=30;j>=0;j--){
        vector<long long> nt;
        long long cnt=0;
        for(auto i:t){
            if(i&(1LL<<j)){
                cnt++;
                nt.push_back(i);
            }
        }
        if(cnt>=m){
            ans|=(1LL<<j);
            t=nt;
        }
    }
    cout << ans;
    return 0;
}
