#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
ll a[N];
vector<ll> fur;
int c,T;
ll n,d,ans;
bool check(int u,int v){
    if(a[v]-a[u]>d) return false;
    else return true;
}
int bsearch(int u){
    int l=u+1,r=n;
    int mid;
    while(l<r){
        mid=(l+r+1)>>1;
        if(check(u,mid))    l=mid;
        else   r=mid-1;
    }
    return l;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>T;
    while(T--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        fur.clear();
        for(int i=1;i<n;i++){
            fur.push_back(bsearch(i));
        }
        for(int i=1;i<n;i++){
            if(fur[i-1]==i+1||fur[i-1]==n)   continue;
            ans+=fur[fur[i-1]-2]-fur[fur[i-1]-3];
        }
        cout<<ans<<'\n';
    }
    return 0;
}
//coded by LF Jyouhan
//In the world filled with fake love,remember to love yourself.
