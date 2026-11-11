#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t;
int n;
long long d;
long long x[N];
int nxt[N];
long long dp[N],dp2[N];
vector<int>G[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n;i++){
            int l=i+1,r=n,ans=0;
            while(l<=r){
                int mid=(l+r)/2;
                if(x[mid]-x[i]<=d){
                    ans=mid;
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
            nxt[i]=ans;
        }
        for(int i=n;i>=1;i--){
            if(nxt[i] && x[nxt[i]]-x[i-1]>d)    dp[i]+=dp[nxt[i]];
            if(nxt[i] && x[nxt[i]]-x[i-1]>d){
                int l=i+1,r=nxt[i],ans=0;
                while(l<=r){
                    int mid=(l+r)/2;
                    if(x[mid]-x[i-1]>d){
                        ans=mid;
                        r=mid-1;
                    }
                    else{
                        l=mid+1;
                    }
                }
                dp[i]+=nxt[i]-ans+1;
            }
        }
        for(int i=1;i<=n;i++){
            if(nxt[i]){
                G[nxt[i]].push_back(i);
            }
        }
        for(int i=1;i<=n;i++){
            for(int xx:G[i]){
                if(nxt[i] && x[nxt[i]]-x[i-1]>d)    dp2[i]+=(dp2[xx]+1);
            }
        }
        long long ans=0;
        for(int i=1;i<=n;i++){
            int xx=nxt[i],xx2=nxt[xx];
            if(xx && xx2){
                if(xx>i+1 && x[xx2]-x[xx-1]<=d && x[xx2]-x[xx-2]>d){
                    if(x[xx-1]-x[i-1]>d){
                        ans+=dp2[i]*dp[xx2];
                        //cout<<"add"<<" "<<i<<" "<<xx2<<" "<<dp2[i]*dp[xx2]<<"\n";
                    }
                    ans+=dp[xx2];
                    //cout<<"add2"<<" "<<i<<" "<<dp[xx2]<<"\n";
                }
            }
        }
        for(int i=2;i<=n;i++){
            if(nxt[i]){
                for(int xx:G[i]){
                    //xx------i------r
                    int l=i+1,r=nxt[i],ans1=0;
                    while(l<=r){
                        int mid=(l+r)/2;
                        if(x[mid]-x[i-1]<=d){
                            ans1=mid;
                            l=mid+1;
                        }
                        else{
                            r=mid-1;
                        }
                    }
                    l=i+1,r=nxt[i];
                    int ans2=0;
                    while(l<=r){
                        int mid=(l+r)/2;
                        if(x[mid]-x[i-2]>d){
                            ans2=mid;
                            r=mid-1;
                        }
                        else{
                            l=mid+1;
                        }
                    }
                    if(ans1 && ans2 && ans2<=ans1){
                        ans+=(ans1-ans2+1)*(1);
                        //cout<<"add3"<<" "<<ans<<"\n";
                        if(x[i-1]-x[xx-1]>d){
                            ans+=(ans1-ans2+1)*(dp2[xx]);
                            //cout<<"add4"<<" "<<ans1<<" "<<ans2<<" "<<dp2[xx]<<" "<<(ans1-ans2+1)*(dp2[xx])<<"\n";
                        }
                    }
                }
            }
        }
        cout<<ans<<"\n";
        for(int i=1;i<=n;i++){
            dp[i]=dp2[i]=nxt[i]=0;
            G[i].clear();
            x[i]=0;
        }
    }
    return 0;
}