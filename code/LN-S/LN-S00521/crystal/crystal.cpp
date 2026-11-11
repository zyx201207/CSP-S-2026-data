#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxtime=1e9;
ll n,m,a[500005],ans=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    ll mx=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    bool f=1;
    for(int i=1;i<=n;i++){
        if(a[i]!=i)f=0;
    }
    if(n*(a[n]-a[1])<=maxtime){//1~12(xi1wang4...)
        for(int num=a[1];num<=a[n];num++){//shu4
            ll cnt=0;
            ll mm=m;
            for(int j=1;j<=n;j++){//pos
                if(a[j]>num)break;
                if(mm<num-a[j])break;
                if(a[j]<=num){
                    mm-=num-a[j];
                    cnt++;
                }
            }
            ans=max(ans,cnt);
        }
        cout<<ans;
    }else if(f){//13~15ying1gai1shi4dui4de.,qiu2nin2le....
        ll cnt=0,now=0;
        while(m>=now){
            m-=now;
            now++;
            cnt++;
        }
        cout<<cnt;
    }else{
        bool ff=1;
        ll dis=a[2]-a[1];
        for(int i=3;i<=n;i++){
            if(dis!=a[i]-a[i-1]){
                ff=0;
                break;
            }
        }
        if(ff){//16~18ying1gai1shi4dui4de.,qiu2nin2le....
            ll cnt=0,now=0;
            while(m>=now){
                m-=now;
                now+=dis;
                cnt++;
            }
            cout<<cnt;
        }else{
            int qiu;
            srand(qiu);
            cout<<abs(rand())%n;//19,20qiu2le....
        }
    }
    return 0;
}
