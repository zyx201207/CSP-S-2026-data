#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll ans;
pair<ll,char> p[214514];
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        ll a;char c;
        cin>>a>>c;
        pair<ll,char> p1=make_pair(a,c);
        p[i]=p1;
    }
    ll l=0,r=n-1;
    while(l<r){
        ll l_now=p[l].first;
        ll r_now=p[r].first;
        if(p[l].second==p[r].second){
            if(l_now==r_now){
                l++;r--;
            }
            else if(l_now<r_now){
                l++;p[r].first-=l_now;
            }
            else if(l_now>r_now){
                r--;p[l].first-=r_now;
            }
        }
        else {
            if(l_now==r_now){
                ans+=l_now;
                l++;r--;
            }
            else if(l_now<r_now){
                ans+=l_now;
                l++;p[r].first-=l_now;
            }
            else if(l_now>r_now){
                ans+=r_now;
                r--;p[l].first-=r_now;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
