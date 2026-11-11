#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5;
const ll M=1e18+5;

ll n,m,st,k,a[N],ans=0;

bool check_A(){
    for(int i=1;i<=n;i++){
        if(a[i]!=ll(i))return false;
    }
    return true;
}

bool check_B(){
    ll cha=a[2]-a[1];
    for(int i=2;i<=n;i++){
        if(a[i]-a[i-1]!=cha)return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];

    if(check_A()){
        for(int i=1;i<=n;i++){
            ll need=(1+i-1)*(i-1)/2ll;
            if(m>need)ans++;
            else break;
        }
        cout<<ans;
    }else if(check_B()){
        sort(a+1,a+n+1);
        ll cha=a[2]-a[1];
        for(int i=1;i<=n;i++){
            ll need=(cha+(i-1)*cha)*(i-1)/2ll;
            if(m>need)ans++;
            else break;
        }
        cout<<ans;
    }else{
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++){
            k=m,st=a[i];
            bool flag=true;
            for(int j=1;j<=i;j++){
               if(k>=st-a[j])k-=(st-a[j]);
               else{
                    flag=false;
                    break;
               }
            }
            if(!flag)break;
            else ans++;
        }
        cout<<ans;
    }

    return 0;
}
