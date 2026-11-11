#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
typedef long long ll;
ll n,m,a[500020],sum[500020],mx,x;
bool f1;
void solve(){
    ll x=a[2]-a[1],cnt=0;
    for(int i=1;i<n;i++){
        cnt+=x;
        m-=cnt;
        if(m<0){
            cout<<i<<endl;
            return ;
        }
    }
    cout<<n<<endl;
}
int f(int l,int r){
    int x=r;
    while(l+1<r){
        int mid=(r-l)/2+l;
        if(x-mid+1<=(sum[x]-sum[mid-1]+m)/a[x]){
            r=mid;
        }
        else{
            l=mid;
        }
    }
    return r;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==2){
            x=a[2]-a[1];
        }
        if(i>2){
            if(a[i]-a[i-1]!=x){
                f1=1;
            }
        }
    }
    if(!f1){
        solve();
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=n;i>0;i--){
        int k=f(0,i);
        mx=max(mx,ll(i-k+1));
    }
    cout<<mx<<endl;
    return 0;
}
