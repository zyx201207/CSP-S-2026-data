#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[500005];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    ll maxa=0,mina=100000000000000,sum=0;
    for(int i=1;i<=n;i++){
        maxa=max(maxa,a[i]);
        mina=min(mina,a[i]);
    }
    for(int i=1;i<=n;i++){
        sum+=maxa-a[i];
    }
    if(sum<=m){
        cout << n;
        return 0;
    }//tepan

    ll l=mina,r=maxa;
    maxa=0;
    sort(a+1,a+n+1);
    sum=0;
    ll mid=(l+r)/2;
    ll cnt=0;
    while(l<=r){
        sum=0;
        cnt=0;
        //cout << l << " " << r << " " << mid << " " << sum << "\n";
        for(int i=1;i<=n;i++){
            if(a[i]<=mid){
                sum+=(mid-a[i]);
                cnt++;
            }
        }
        if(sum<m){
            l=mid+1;
        }else if(sum==m){
            break;
            //cout << cnt;
            //return 0;
        }else{
            r=mid-1;
        }
        mid=(r+l)/2;
        //cout << l << " " << r << " " << mid << " " << sum << "\n";
        //cout << "\n";
    }
    ll ans=cnt;
    sum=0;
    mid=a[cnt];
    for(int i=1;i<=cnt;i++){
        sum+=a[cnt]-a[i];
    }
    //cout << sum << "\n";
    ll flag=0;
    for(int i=1;i<=n;i++){
        if(a[i]>mid){
            flag=i;
            break;
        }
    }
    //cout << flag << "\n";
    for(ll i=1,j=flag;j<=n;){
        //cout << mid << "\n";
        //cout << cnt << " " << i << " " << j << " " << ans << " " << sum << "\n";
        if((a[j]-mid)*cnt+sum<=m){
            sum+=(a[j]-mid)*cnt;
            mid=a[j];
            cnt++;
            j++;
        }else{
            sum-=(a[j-1]-a[i]);
            cnt--;
            i++;
        }
        ans=max(ans,cnt);
        //cout << cnt << " " << i << " " << j << " " << ans << " " << sum << "\n";
        //cout << "\n";
    }
    cout << ans;
    return 0;
}