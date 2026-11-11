#include<bits/stdc++.h>
using namespace std;
using in=long long;
in sum,ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    vector<in>v;
    in n,m;
    in x;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x;
        v.push_back(x);
    }
    for(int i=30;i>=0;i--){
        sum=0;
        vector<in>a;
        for(int j=0;j<v.size();j++){
            if((v[j]&(1ll<<i))){
                a.push_back(v[j]);
                sum++;
            }
        }
        if(sum>=m){
            ans|=(1ll<<i);
            v=a;
        }
    }
    cout<<ans;
    return 0;
}
