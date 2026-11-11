#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=5e5+5;
ll n,m;
ll a[MAXN];
bool f_ai=1;
bool f_dc=1;
ll cnt[MAXN];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    ll cha;
    for(int i=1;i<=n;i++){

        cin>>a[i];
        if(a[i]!=i) f_ai=0;
        if(i==2){
            cha=a[i]-a[i-1];
        }else if(i!=1){
            if(a[i]-a[i-1]!=cha) f_dc=0;
        }

    }
    if(f_ai){
        for(int i=1;i<=MAXN;i++){
            m-=i;
            if(m<0){
                if(i>n) cout<<n;
                else cout<<i;
                return 0;
            }
        }
    }
    if(f_dc==1){
        for(int i=cha,j=1;i<=MAXN;i+=cha,j++){
            m-=i;
            if(m<0){
                if(j>n) cout<<n;
                else cout<<j;
                return 0;
            }
        }
    }
    ll l=1,r=2;
    ll cc=a[2]-a[1];
    cnt[1]=1;
    sort(a+1,a+1+n);
    //ll cnt[MAXN];
    while(r<n){
        if(cc>m){
            cc-=(a[r]-a[l]);
            l++;
            cnt[r]--;
            //cout<<1;
        }else{

            cnt[r]+=cnt[r-1]+1;
            r++;
            cc+=((a[r]-a[r-1])*cnt[r-1]);
           // cout<<0;
        }//cout<<cc<<" ";
    }
    ll maxx=LONG_MIN;
    for(int i=1;i<=n;i++){
            cout<<cnt[i]<<" ";
        if(cnt[i]>maxx) maxx=cnt[i];
    }
    cout<<maxx;
}
