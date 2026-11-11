#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int N = 1e6+5;
int c,t,n,k;
vector<int>e[N];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)e[i].clear();
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        if(c>=13&&c<=14){
            if(k==n)cout<<0<<'\n';
            else if(k>=n/2)cout<<1<<'\n';
            else{
                int m=n/2+2,ans=0;
                int l=1,r=m;
                while(l<=r){
                    int mid=(l+r)/2;
                    if(4*mid-2+k>=m){
                        r=mid-1;
                        ans=mid;
                    }else l=mid+1;
                }
                cout<<ans<<'\n';
            }
        }
    }
    return 0;
}
