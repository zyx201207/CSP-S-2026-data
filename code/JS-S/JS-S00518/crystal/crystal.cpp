#include<bits/stdc++.h>
using namespace std;

#define int long long

int a[500005],cha[500005];

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    bool op1=1,op2=1;

    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i) op1=0;
        if(i>2 && a[i]-a[i-1]!=a[i-1]-a[i-2]) op2=0;
    }

    if(op1){
        unsigned long long res=0,per=1;
        for(int i=2;i<=n;i++){
            res+=per;
            per++;
            if(res>m){
                cout<<i-1;
                return 0;
            }
        }
        cout<<n;
        return 0;
    }

    if(op2){
        unsigned long long res=0,per=a[2]-a[1];
        for(int i=2;i<=n;i++){
            res+=per;
            per+=(a[2]-a[1]);
            if(res>m){
                cout<<i-1;
                return 0;
            }
        }
        cout<<n;
        return 0;
    }

    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
         cha[i]=a[i]-a[i-1];
    }

    unsigned long long ans=1;
    for(int i=1;i<=n;i++){
        unsigned long long cnt=1,now=1,cost=0;
        while(now<n){
            if(m-cost>=cnt*cha[now+1]){
                cost=cost+cnt*cha[now+1];
                cnt++;
                now++;
                ans=max(ans,cnt);
            }
            else break;
        }
    }
    cout<<ans;

    return 0;

}
