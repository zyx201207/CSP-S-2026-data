#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
const int N=2e5+10;
ll a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("ans.out","w",stdout);
    cin>>n>>m;
    bool ok=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>=4)ok=0;
    }

    if(m==1){
        ll maxa=0;
        for(int i=1;i<=n;i++){
            maxa=max(maxa,a[i]);
        }
        cout<<maxa<<endl;
        return 0;
    }
    else if(m==2){
        ll maxa=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n&&j!=i;j++){
                maxa=max(maxa,(a[i]&a[j]));
            }
        }
        cout<<maxa<<endl;
        return 0;
    }
    else if(m==n){
        ll ans=a[1];
        for(int i=2;i<=n;i++){
            ans=(ans&a[i]);
        }
        cout<<ans<<endl;
        return 0;
    }
    else if(ok){
        ll cnt1=0,cnt2=0,cnt3=0;
        for(int i=1;i<=n;i++){
            if(a[i]==1)cnt1++;
            if(a[i]==2)cnt2++;
            if(a[i]==3)cnt3++;
        }
        if(cnt3>=m)cout<<3;
        else if(cnt3+cnt2>=m)cout<<2;
        else if(cnt3+cnt1>=m)cout<<1;
        else cout<<0;
        return 0;
    }
    else{
        sort(a+1,a+n+1);
        cout<<a[n-m+1]<<endl;
        return 0;
    }
    return 0;
}
