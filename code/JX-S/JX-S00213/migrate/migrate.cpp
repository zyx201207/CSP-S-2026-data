#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=2e6+5;
ll lst[N];
vector<int> dp[305];

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int c, t, n;
    ll d;
    int cnt, p, mch;
    int l, r, mid, res;
    ll ans;
    bool A;
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1; i<=n; i++){
            cin>>lst[i];
        }
        if(n<=3){
            cout<<0<<endl;
            continue;
        }
        /////////////////////////
        ans=0;
        if(n<=300){
            for(int s=1; s<=n; s++){
                for(int i=s; i<=n; i++) dp[i].clear();
                dp[s].push_back(1);
                for(int i=s+1; i<=n; i++){
                    l=s, r=i-1, res=500;
                    while(l<=r){
                        mid=(l+r)/2;
                        if(lst[i]-lst[mid]<=d){
                            res=min(res, mid);
                            r=mid-1;
                        }else l=mid+1;
                    }
                    for(int j=res; j<i; j++){
                        for(int stp:dp[j]){
                            dp[i].push_back(stp+1);
                        }
                    }
                    if(dp[i].size()<2) continue;
                    sort(dp[i].begin(), dp[i].end());
                    if(dp[i][0]==dp[i][1]){
                        if(dp[i].size()==2) ans++;
                        else if(dp[i][1]!=dp[i][2]) ans++;
                    }
                }
            }
            cout<<ans<<endl;
            continue;
        }
        /////////////////////////
        A=1;
        for(int i=2; i<=n-1; i++){
            if(lst[i]*2!=lst[i-1]+lst[i+1]){
                A=0; break;
            }
        }
        if(d/(lst[2]-lst[1])!=2) A=0;
        //cout<<"A"<<A<<endl;
        if(A){
            cout<<n-3<<endl;
            continue;
        }
        //////////////////////////
        cnt=0, ans=0;
        for(int i=2; i<=n-1; i++){
            if(lst[i]-lst[1]<=d&&lst[n]-lst[i]<=d){
                cnt++;
                if(cnt==1) p=i;
            }
            if(cnt>2) break;
        }
        //cout<<"cnt:"<<cnt<<endl;
        if(cnt==2){
            for(int i=1; i<p; i++){
                l=p+2, r=n, mch=n;
                while(l<=r){
                    mid=(l+r)/2;
                    if(lst[mid]-lst[i]>d){
                        mch=min(mch, mid);
                        r=mid-1;
                    }else l=mid+1;
                }
                ans+=n-mch+1;
            }
            cout<<ans<<endl;
            continue;
        }
    }
    return 0;
}
