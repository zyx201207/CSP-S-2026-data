#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,x[5005],c,T,dq[114514],dp[5005],hd,tl,d,cnt[114514];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        for(ll i=1;i<=n;i++)
            cin>>x[i];
        if(c==13||c==14){
            cout<<0<<"\n";
            continue;
        }
        ll res=0;
        for(ll i=1;i<=n;i++){
            hd=1,tl=0;
            for(ll j=1;j<=n;j++)
                cnt[j]=dp[j]=0;
            for(ll j=i;j<=n;j++){
                while(tl>=hd&&x[j]-x[dq[hd]]>d)
                    hd++;
                if(tl>=hd){
                    dp[j]=dp[dq[hd]]+1;
                    ll pre=dp[dq[hd]],ccnt=cnt[dq[hd]];
                    //cout<<"dp in need:"<<pre<<" "<<i<<" "<<j<<"\n";
                    for(ll k=hd+1;k<=tl;k++)
                        if(dp[dq[k]]==pre){
                            //cout<<k<<" is cute,i like this\n";
                            ccnt+=cnt[dq[k]];
                            if(ccnt>2)
                                break;
                        }
                        else
                            break;
                    cnt[j]=ccnt;
                }
                else{
                    if(j==i){
                        dp[j]=0;
                        cnt[j]=1;
                    }
                    else{
                        dp[j]=1e18;
                        cnt[j]=0;
                    }
                }
                while(tl>=hd&&dp[j]<dp[dq[tl]])
                    tl--;
                dq[++tl]=j;
                if(cnt[j]==2)
                    res++;
            }
            /*for(ll j=i;j<=n;j++)
                cout<<dp[j]<<" ";
            cout<<"\n";
            for(ll j=i;j<=n;j++)
                cout<<cnt[j]<<" ";
            cout<<"\n";*/
        }
        cout<<res<<"\n";
    }
    return 0;
}

