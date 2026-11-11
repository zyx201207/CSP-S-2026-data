#include<bits/stdc++.h>
using namespace std;

const int N=2e6+5;
int c,t;

void solve(){
    int n,d;cin>>n>>d;
    vector<int> x(2+n),q(n+2),h(n+2),left(n+2),right(n+2);
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    for(int i=1;i<=n;i++){
        if(x[i]-d==x[1]+1){
            q[i]=i-1;
        }else if(x[i]-d<x[1]+1){
            q[i]=i;
        }else{
            int ls=lower_bound(x.begin(),x.end(),x[i]-d-1)-x.begin();
            q[i]=i-ls;
        }
        if(x[i]+d==x[n]-1){
            h[i]=n-i;
        }else if(x[i]+d>x[n]-1){
            h[i]=n-i+1;
        }else{
            int ls=upper_bound(x.begin(),x.end(),x[i]+d+1)-x.begin();
            ls-=1;
            h[i]=ls-i;
        }
    }
    for(int i=1;i<=n;i++){
        right[i]=right[i-q[i]]+1;
    }
    for(int i=n;i>=1;i--){
        left[i]=left[i+h[i]]+1;
    }
    vector<int> mp(N*2);
    int ans=0;
    for(int i=1;i<=n;i++){
        int checkval=i-q[i]+2+N,index=h[i]-1+i+N;
        
        int v=mp[checkval];
        ans+=v*left[i];
        mp[index]+=right[i];
    }
    cout<<ans<<endl;

    //debug
    // cout<<"____debug output____"<<endl;
    // for(int i=1;i<=n;i++){
    //     // cout<<mp[h[i]+i+N]<<" ";
    //     cout<<i-q[i]+2<<" ";
    //     // cout<<q[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=1;i<=n;i++){
    //     cout<<h[i]+i<<" ";
    //     // cout<<h[i]<<' ';
    // }
    // cout<<endl;

}

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        solve();
    }
    return 0;
}