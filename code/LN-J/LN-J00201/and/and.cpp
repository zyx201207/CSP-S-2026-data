#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
#define ll long long
ll a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==n){
        ll ans=a[1];
        for(int i=2;i<=n;i++){
            ans=ans & a[i];
        }
        cout<<ans;
    }else if(m==1){
        ll ans=a[1];
        for(int i=2;i<=n;i++){
            ans=max(ans,a[i]);
        }
        cout<<ans;
    }else if(m==n-1){
        ll ans=0;
        for(int i=1;i<=n;i++){
            ll cnt=a[1],j=2;
            if(i==1){
                cnt=a[2],j=3;
            }
            for(;j<=n;j++){
                cnt=cnt & a[j];
            }
            ans=max(ans,cnt);
        }
        cout<<ans;
    }else if(m==2){
        ll ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j){
                    ll cnt=a[i] & a[j];
                    ans=max(ans,cnt);
                }
            }
        }
        cout<<ans;
    }else{
        ll ans=0;
        for(int i=1;i<=n;i++){
            ll cnt=0;
            int c=1;
            if(c==m){
                break;
            }
            for(int j=1;j<=n;j++){
                ll ccnt=cnt;
                if(cnt==0){
                    ccnt=a[i];
                }
                if(j!=i){
                    ccnt=ccnt & a[j];
                    cnt=max(cnt,ccnt);
                    if(j==1){
                        cnt=ccnt;
                    }
                    c++;
                }
            }
            ans=max(ans,cnt);
        }
        cout<<ans;
    }
    return 0;
}
