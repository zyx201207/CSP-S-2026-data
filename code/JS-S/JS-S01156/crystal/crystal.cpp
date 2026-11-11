#include<bits/stdc++.h>
#define ll long long
#define N 500005
using namespace std;

ll n;
ll ans,a[N],m;

int main(){
    freopen("crystal4.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(ll i=1;i<n;i++){
        if(a[i+1]==a[i]){
            ans++;
            continue;
        }
        if(m==0){
            break;
        }
        ll cnt=m/(a[i+1]-a[i]);
        m-=min(i,cnt)*(a[i+1]-a[i]);
        ans=max(ans,min(i,cnt));
        if(cnt<i){
            break;
        }
        //cout<<ans<<" ";
        /*
        while(m>0&&cnt<i){
            cnt++;
            if(m-(a[i+1]-a[i])>=0){
                m-=(a[i+1]-a[i]);
            }
            else break;

        }
        ans=max(ans,cnt);
        if(cnt!=i) break;
        */
    }
    cout<<ans+1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
