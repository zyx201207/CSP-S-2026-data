#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
ll n,m;
ll a[500005];
ll ans[500005];
inline ll findx(vector<ll>b,ll x){
    for(int i=0;i<b.size();i++)if(b[i]==x)return i;
    return -1;
}
int main(){
    freopen("card.out","w",stdout);
    freopen("card.in","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        
    }
    for(int i=1;i<=n;i++){
        vector<ll>b;
        for(int j=i;j<=n;j++){
            if(findx(b,a[j])!=-1){
                while(b[b.size()-1]!=a[j])b.pop_back();
                b.pop_back();
            }
            b.push_back(a[j]);
        }
        for(int j=0;j<b.size();j++){
            ans[b[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}