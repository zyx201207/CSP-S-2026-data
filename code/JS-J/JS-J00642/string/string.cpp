#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using db=double;
using ldb=long double;


ll n;
ll a[(ll)2e5+5];
char c[(ll)2e5+5];

int main(){

    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    
    //Write Code HERE!!!!!!!!!
    cin>>n;
    // ll a[5];char c[5];
    ll sumx=0;
    for(ll i=1;i<=n;++i){
        ll x;
        char cx;
        char kg;//kongge
        cin>>x>>cx;
        a[i]=x;
        c[i]=cx;
        sumx+=x;
    }
    ll now=0;
    ll nowi=1;
    ll lasti=n;
    ll ans=0;
    if(sumx%2==1){
        ll test=0;
        for(ll i=1;i<=n;++i){
            test+=a[i];
            if(test>=(sumx+1)/2){
                a[i]--;
                sumx--;
                break;
            }
        }
    }
    
    while(now<(sumx/2)){
        ll lenow=a[nowi];
        now+=a[nowi];
        
        for(;lasti>=1;){
            if(c[lasti]==c[nowi]){
                if(lenow>=a[lasti]){
                    
                    lenow-=a[lasti];
                    lasti--;
                    if(lenow==0){
                        break;
                    }

                }else{
                    a[lasti]=a[lasti]-lenow;
                    lenow=0;
                    break;
                }
            }else if(c[lasti]!=c[nowi]){
                if(lenow>=a[lasti]){
                    
                    ans+=a[lasti];
                    lenow-=a[lasti];
                    lasti--;
                    if(lenow==0){
                        break;
                    }
                }else{
                    ans+=lenow;
                    a[lasti]=a[lasti]-lenow;
                    lenow=0;
                    break;
                }
            }

        }
        nowi++;
    }
    cout<<ans<<"\n";
    return 0;
}
