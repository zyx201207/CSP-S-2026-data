#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2000010;
ll c,t,x[N],n,d,ans,cr[N],cl[N],ar[N],al[N];

ll bfind(ll l, ll r, ll y){
    ll mid=r;
    while(l<r){
        mid =(l+r+1)>>1;
        if(x[mid]>y){
            r=mid-1;
        }else{
            l=mid;
        }
    }
    return l;
}
ll bfind2(ll l, ll r, ll y){
    ll mid=r;
    while(l<r){
        mid =(l+r)>>1;
        if(x[mid]>=y){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    return l;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        memset(cl,0,sizeof(cl));
        memset(cr,0,sizeof(cr));
        memset(al,0,sizeof(al));
        memset(ar,0,sizeof(ar));
        ans=0;
        for(int i = 1; i <= n; i++) {
            cin >> x[i];
        }
        if(c==11||c==12){
            ll a=x[2]-x[1];
            ll b=d/a;
            if(b<2){
                cout << 0 << endl;
            }else{
                for(int i = 1; i <= n; i++) {
                    if(2*b+i-1<=n){
                        ans+=(b-1);
                    }else if(b+i<n){
                        ans+=(n-b-i);
                    }else{
                        break;
                    }
                }
                cout << ans << endl;
            }
            continue;
        }
        for(int i = 1; i <= n; i++){
            int j=bfind(1,n,x[i]+d);
            ar[i]=j;
            if(j==n)continue;
            //if(j==i+1)continue;
            cr[j]+=cr[i]+1;
        }
        for(int i = n; i >= 1; i--){
            int j=bfind2(1,n,x[i]-d);
            al[i]=j;
            if(j==1)continue;
            //if(j==i-1)continue;
            cl[j]+=cl[i]+1;
        }
        for(int i = 2; i < n-1; i++){
            if(al[i+1]==i||ar[i]==i+1)continue;
            ans+=(cl[i]*cr[i+1]);
        }
        cout << ans << endl;
    }
    return 0;
}

