#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll a[N],cnt[N];
ll b[N];
__int128 sum[N];
ll n,K;
bool check(int mid){
    for(int i=1;i<=n;i++){
        b[i]-=a[mid];
        b[i]=-b[i];
    }
    __int128 sum=0;
    for(int i=1;i<=mid;i++){
        sum+=b[i];
    }
    for(int i=1;i<=n;i++){
        b[i]=-b[i];
        b[i]+=a[mid];
    }
    return sum<=K;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>K;
    ll zm=0;
    ll mm=2e9;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        //a[i]+=100;
        zm=max(zm,a[i]);
        mm=min(mm,a[i]);
    }
    if(mm<=0){
        for(int i=1;i<=n;i++){
            a[i]-=mm;
        }
        zm-=mm;
        mm-=mm;
    }
    if(zm<=201){
        for(int i=1;i<=n;i++){
            cnt[a[i]]++;
        }
        ll ans=0;
        for(int i=0;i<=zm;i++){
            ll c=0;
            ll k=K;
            for(int j=i;j>=0;j--){
                if((i-j)*cnt[j]<=k){
                    k-=(i-j)*cnt[j];
                    c+=cnt[j];
                }else{
                    c+=(k/(i-j));
                    break;
                }

            }
            ans=max(ans,c);
        }
        cout<<ans;
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        b[i]=a[i];
    }
    int l=1,r=n;
    while(l<r){
        int mid=(l+r+1)>>1;
        if(check(mid)){
            l=mid;
        }else{
            r=mid-1;
        }
    }
    cout<<l;
    return 0;
}
