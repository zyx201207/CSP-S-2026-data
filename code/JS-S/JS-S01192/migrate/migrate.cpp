#include<bits/stdc++.h>
using namespace std;
#define int long long
#define out(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" ";cout<<'\n'
#define zero(a) memset(a,0,sizeof a)
#define all(a) a.begin(),a.end()
#define fi first
#define se second
#define pb push_back
const int MAX=(1<<31)-1;
const int MOD=1e9+7;
const int N=2000020;
int c,T,n,d;
int a[N];
pair<int,int> p[N];
int before[N];
int after[N];
vector<int> ara[N],arb[N];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        for(int i=0;i<n;i++) p[i]={-1,-2};
        for(int i=0;i<n;i++){
                cin>>a[i];
        ara[i].clear();
        arb[i].clear();
        }
        int id=0;
        for(int i=1;i<n;i++){
            while(a[i]-a[id]>d) id++;
            before[i]=id;
            //if(a[i]-a[id]!=d) before[i]--;
        }
        id=n-1;
        int l=0,r;
        for(int i=n-1;i>=0;i--){
            while(a[id]-a[i]>d) id--;
            after[i]=id;
            //if(a[i]-a[id]!=-d) after[i]++;
        }
        /*for(int i=1;i<n;i++){
            if(after[i]==after[i-1]) continue;
            else{
                p[after[i-1]]={l,i-1};
                l=i;
            }
        }
        p[after[n-1]]={l,n-1};
        for(int i=0;i<n;i++){
            int t=i;
            while()
        }
        out(dp,n);
        out(f,n);
        //for(int i=0;i<n;i++) cout<<i<<" "<<p[i].fi<<" "<<p[i].se<<endl;
        //out(before,n);
        //out(after,n);
        int ans=0;
        for(int i=1;i<n;i++){
            if(before[i]<i-1){
                int K=before[i]+1;
                //cout<<K<<endl;
                if(p[K].fi==-1) continue;
                else{
                        cout<<p[K].first<<" "<<p[K].second<<endl;
                    ans+=Sum[p[K].se];
                    if(p[K].fi!=0) ans-=Sum[p[K].fi-1];
                }
            }
        }
        */
        int ans=0;
        for(int i=0;i<n-1;i++){
                int k=i;
                ara[i].pb(i);
            while(k!=n-1 && before[after[k]]==k &&  after[k]!=k){
                k=after[k];
                ara[i].pb(k);
            }
        }
        for(int i=1;i<n;i++){
                int k=i;
                arb[i].pb(i);
            while(k!=0 &&after[ before[k]]==k && before[k]!=k){
                k=before[k];
                arb[i].pb(k);
            }
            sort(all(ara[i]));
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                    int ok=0;
                    for(int x:ara[i]){
                        for(int y:arb[j]){
                            if(after[x]==before[y]+1){
                            ans++;
            ok=1;
                            break;
                    }
                        }
                        if(ok) break;
                    }
            }
        }
        cout<<ans<<endl;
        //int ans=0;
        //for(int i=0;i<n;i++) ans+=dp[i][1];
        //cout<<ans<<endl;
    }
    return 0;
}
/*
0 1
10 3
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983


9
*/
