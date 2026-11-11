#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define endl '\n'
const int inf=0x3f3f3f3f;
const double eps=1e-9;
using namespace std;

const int maxn=200005;
ll a[maxn],ans,n; char c[maxn];

int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
    int l=1,r=n;
    while(l<r){
        ll val=min(a[l],a[r]);
        if(c[l]!=c[r]) ans+=val;
        a[l]-=val; a[r]-=val;
        if(a[l]==0) l++;
        if(a[r]==0) r--;
    }
    cout<<ans;
    //08:50


    return 0;
}
