#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    if(c==11||c==12){
        while(t--){
            int n,d;
            cin>>n>>d;
            int a[n+5];
            for(int i=1;i<=n;i++){
                cin>>a[i];
            }
            int dd=a[2]-a[1];
            int p=d/dd;
            int ans=0;
            if(p>1){
                p=p*2-1;
                ans=n-p;
            }
            cout<<max(ans,0LL)<<"\n";
        }
        return 0;
    }
    while(t--){
        int n,d;
        cin>>n>>d;
        int a[n+5];
        map<int,int>mp;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            mp[a[i]]++;
        }
        unsigned int ans=0;
        for(int i=1;i<n;i++){
            ans+=mp.count(a[i]+2*d-1)*(mp.count(a[i]+d)+mp.count(a[i]+d-1));
        }
        cout<<ans/2<<"\n";
    }
    return 0;
}//8pts
