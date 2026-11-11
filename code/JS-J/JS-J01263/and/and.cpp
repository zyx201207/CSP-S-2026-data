#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m,a[N];
multiset<int>w[40],tmp;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int x=a[i],tcnt=0;
        while(x){
            tcnt++;
            if(x&1){
                w[tcnt].insert(a[i]);
            }
            x>>=1;
        }
    }
    // for(int i=1;i<=30;i++){
    //     cout<<i<<": ";
    //     for(auto val:w[i]){
    //         cout<<val<<' ';
    //     }
    //     cout<<endl;
    // }
    int ans=0;
    for(int i=30;i>=1;i--){
        if(w[i].size()<m)continue;
        else{
            for(auto val:w[i]){
                if(w[i-1].count(val)){
                    tmp.insert(val);
                }
            }
            // cout<<i<<":";
            // for(auto val:tmp){
            //     cout<<val<<' ';
            // }
            // cout<<'\n';
            w[i-1]=tmp;
            ans+=(1ll<<(i-1));
            if(tmp.size()<m)break;
            tmp.clear();
        }
    }
    cout<<ans;
    return 0;
}