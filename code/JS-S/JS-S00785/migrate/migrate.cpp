#include <bits/stdc++.h>
#define int long long
using namespace std;
double a[2000005],way[2000005];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        cerr<<"\n-----\n";
        int n,d,ans=0;
        cin>>n>>d;
        memset(a,0,sizeof a);
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int start=1;start<n;start++){
            memset(way,0,sizeof way);
            way[start]=1;
            for(int i=start+1;i<=n;i++){
                if(a[i]-a[start]<=d)way[i]=1;
                else{
                    int k=i-1;
                    while(a[i]-a[k]<=d){
                        way[i]+=way[k];
                        k--;
                    }
                }
                cerr<<"From "<<start<<" to "<<i<<", "<<way[i]<<" ways.\n";
            }
            for(int i=1;i<=n;i++)ans+=(way[i]==2);
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
-2 -1 0 1 3
 1  0 0 0 0
 1  1 0 0 0
 1  1 1 0 0
 1  1 1 1 0
 1  1 1 1 2
 */
