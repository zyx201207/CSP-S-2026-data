#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 5e5+5;

ll n,m,a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (int i=1; i<=n; i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    ll ans=0,cur=0;
    for (int i=1,j=1; i<=n; i++){
        if (i==1){
            ans=max(ans,1ll);
        }
        else{
            ll dif=a[i]-a[i-1];
            cur+=dif*(i-j);
            while (cur>m){
                cur-=(a[i]-a[j]);
                j++;
            }
            ans=max(ans,(ll)i-j+1);
        }
    }
    cout<<ans<<"\n";
    return 0;
}

/*
- Read the problem statements carefully.
- int/long long/__int128.
- The memory limit: /usr/bin/time -v ./T1
- The time limit.
*/

// world.execute(me);