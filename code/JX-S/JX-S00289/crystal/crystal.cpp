#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,a[500005];
ll ans=1;
bool f1=1,f2=1;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i) f1=0;
        if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]) f2=0;
    }
    sort(a+1,a+n+1);
    if(f1){
        ll t=0;
        bool f=1;
        for(int i=1;i<=n;i++){
            if(t+i<=m){
                t+=i;
            }else{
                f=0;
                cout<<i<<endl;
                break;
            }
        }
        if(f) cout<<n<<endl;
        return 0;
    }
    if(f2){
        ll cost=0,b=a[2]-a[1];
        ll c=b;
        for(int i=2;i<=n;i++){
            cost+=b;
            b+=c;
            if(cost>m){
                cout<<i-1<<endl;
                return 0;
            }
        }
        cout<<n<<endl;
        return 0;
    }
    int dp[n+1]={},cost[n+1]={};
        dp[1]=1;
        for(int i=2;i<=n;i++){
            cost[i]=cost[i-1]+i*(a[i]-a[i-1]);
            // cout<<a[i]<<' '<<a[i-1]<<' '<<a[i]-a[i-1]<<endl;
            if(cost[i]<=m){
                dp[i]=i;
            }else{
                // cost[i]-=a[i]-a[1];
                dp[i]=dp[i-1];
                int tmp=cost[i];
                for(int j=1;i-j>dp[i];j++){
                    tmp-=a[i]-a[j];
                    if(tmp<=m){
                        dp[i]=i-j;
                        // cost[i]=tmp;
                        // cout<<i<<' '<<a[i]<<' '<<j<<' '<<dp[i-1]<<endl;
                        break;
                    }
                }
            }
            // cout<<cost[i]<<' '<<dp[i]<<endl;
        }
        cout<<dp[n]+1<<endl;
    return 0;
    
}

/*
<<SAIKAI>> -- Mili
(Section)
I knew I must step up.
You deserve the world and more.
The truth is that you'd rather
spend our limited time together.

Protection alone is not enough,
providing cannot fill a ***(i forgot) heart
thirsting for love.I questioned my self a lot...

What do I know about love?
How can I recreate what I've never had?
All I know is that I must
keep you thriving.
If nutrients are what you lack,
I'll water you with every drop of blood
I have.
But now I know that

sacrifice is the easy path,
my absence cannot ever change the fact.
I wanted the very best for you,
believe me.
Our red threads can never be cut,
and S is not for Sayonara.
Will you forgive me at last?
*/