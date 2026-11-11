#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll a[N],minn[N];
int main(){
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n>=5e5){
        int maxn=a[1]-a[2];
        for(int i=1;i<=n;i++){
            if(m==0||maxn>m){
                cout<<i-1;
                return 0;
            }else m=m-maxn;
        }
    }
    for(ll i=1;i<=n;i++){
        minn[i]=(i-1)*llabs(a[i]-a[i-1])+minn[i-1];
    }
    sort(minn+1,minn+n+1);
    for(int i=1;i<=n;i++){
        if(m>=minn[i]&&minn[i+1]>m){
            cout<<i;
        }
    }

    return 0;
}
