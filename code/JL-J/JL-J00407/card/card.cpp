#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll nn[500005],mm[500005];
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    string s="";
    for(ll i=1;i<=n;i++){
        cin>>nn[i];
    }
    int k=1;
    while(k<n){
            int ans=0;
        for(ll i=k;i<=n;i++){
            ll t=s.find(nn[i]);
            if(t==-1) s+=to_string(nn[i]);
            else {
                    ll l=s.size()-1;
                s.erase(t,l);
            s+=to_string(nn[i]);
            }
        }
        for(int i=0;i<s.size();i++){
            if(s[i]-'0'==k) ans++;
        }
    cout<<ans<<" ";
    k++;
    s="";
    }
    return 0;
}
