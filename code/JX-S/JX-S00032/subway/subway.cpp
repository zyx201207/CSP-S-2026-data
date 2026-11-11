#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll c,n,m,d,q;
ll w[501]={},a[501][1001]={},t[501][1001]={};
ll plan_x[100001]={};
ll plan_y[100001]={};
ll k[501]={};



bool bj[501][20001]={};


int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>c>>n>>m>>d>>q;
    for(ll i=1;i<=m;i++){
        cin>>w[i];
    }
    for(ll i=1;i<=n;i++){
        cin>>k[i];
        for(ll j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            bj[i][j]=1;
        }
    }
    for(ll i=1;i<=q;i++){
        cin>>plan_x[i]>>plan_y[i];
        ll xx,xy,yx,yy;
        for(ll j=1;j<=n;j++){
            for(ll e=1;e<=m;e++){
                if(bj[j][plan_x[e]]==1){
                    xx=j;
                    xy=e;
                }
                if(bj[j][plan_y[e]]==1){
                    yx=j;
                    yy=e;
                }
            }
        }
        ll ans=w[plan_x[i]]+w[plan_y[i]];
        if(xx==yx){
            cout<<ans<<endl;
            continue;
        }
        else{
            ll iop2=0;
            for(ll j=1;j<=n;j++){
                ll iop1=0;
                for(ll p=1;p<=m;p++){
                    ll iop=0;
                    for(ll o=1;o<=n;o++){
                        if(bj[o][p]==1 and o!=j){
                            if(yx==o){
                                ans+=t[o][m];
                                cout<<ans;
                                iop=1;
                                break;
                            }
                            else{
                                ans+=t[o][m];
                            }
                        }
                    }
                    if(iop==1){
                        iop1=1;
                        break;
                    }

                }
                if(iop1==1){
                    iop2=1;
                    break;
                }
            }
            if(iop2==1){
                break;
            }
        }



    }









    return 0;
}
