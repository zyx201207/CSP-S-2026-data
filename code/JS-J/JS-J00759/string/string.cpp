#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MAXN=200005;
ll n;
pair<ll,char> a[MAXN];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
    }
    ll l=1,r=n,ans=0;
    while(l<r){
        if(a[l].second!=a[r].second){
            if(a[l].first>a[r].first){
                ans+=a[r].first;
                a[l].first-=a[r].first;
                a[r].first=0;
                r--;
            }else{
                ans+=a[l].first;
                a[r].first-=a[l].first;
                a[l].first=0;
                l++;
            }
        }else{
            if(a[l].first>a[r].first){
                a[l].first-=a[r].first;
                a[r].first=0;
                r--;
            }else{
                a[r].first-=a[l].first;
                a[l].first=0;
                l++;
            }
        }
    }
    cout<<ans;
    return 0;
}