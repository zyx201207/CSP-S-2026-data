#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m,ans=-1;
    bool fa=1,fb=1;//te shu xing zhi a or b
    cin>>n>>m;
    vl a(n+1);
    FOR(i,1,n){
        cin>>a[i];
    }
    FOR(i,1,n){
        if(a[i]!=i){
            fa=0;
            break;
        }
    }
    ll d=a[2]-a[1];
    FOR(i,2,n){
        if(a[i]-a[i-1]!=d){
            fb=0;
            break;
        }
    }
    if(fa){
        //dao a[i] de ju li shi (i*(i-1))/2
        ll i=2;
        while((i*i-1)/2<=m&&i<=n){
            i++;
        }
        cout<<i;
    }else if(fb){
        ll i=2;
        while(d*(i*i-1)/2<=m&&i<=n){
            i++;
        }
        cout<<i;
    }else{
        sort(a.begin()+1,a.end());
        FOR(i,1,n){//bianli xuan ze de mu biao
            ll j=1,cnt=1,ct=m;
            while(a[j]<=a[i]){
                ct-=abs(a[j]-a[i]);
                if(ct<0){
                    break;
                }
                cnt++;
                j++;
            }
            ans=max(ans,cnt-1);
        }
        cout<<ans;
    }
}
//i am luogu user 1457377
//i am also sc-j 00229
//rp++ ak ioi;
//this afternoon i use linux so there are no chinese
//thanks for looking my code!
//wo shi quan jifang zui hao zhi ren ,only i use linux
