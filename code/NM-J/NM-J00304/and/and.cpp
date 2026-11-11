#include <bits/stdc++.h>
using namespace std;

int n,m;
long long minn = 1e9,cnt_min;
long long a[200005],vis[25][25];
long long ans = pow(2,30)-1;
bool cmp(long long a,long long b){
    //cout<<a<<' '<<b<<"   ";
    long long cnta = 0,cntb = 0,tta = 0,ttb = 0,ta = 0,tb = 0;
    while(a!=0){
            if (a%2) cnta++;
        ta = a%2+ta*10+1;
        a/=2;
    }
    while(b!=0){
        if (b%2) cntb++;
        tb = b%2+tb*10+1;
        b/=2;
    }
    //cout<<ta<<' '<<tb<<"   ";
    while(ta!=0){
        tta = ta%10+tta*10+1;
        ta/=10;
    }
    while(tb!=0){
        ttb = tb%10+ttb*10+1;
        tb/=10;
    }
    //cout<<tta<<' '<<ttb<<endl;
    if (cnta == cntb) return tta>ttb;
    return cnta>cntb;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for (int i = 1;i<=n;i++){
        cin>>a[i];
        //if (a[i]<minn)minn = a[i];
    }

    sort(a+1,a+n+1,cmp);
    for (int i = 1;i<=m;i++){
        ans = ans&a[i];
    }
    /*
    if (n == m){
    for (int i = 1;i<=n;i++){
        ans = ans&a[i];
    }}
    if (m == 2){
        for (int i = 1;i<=n;i++){
            for (int j = 1;j<=n;j++){
                if (a[i]&a[j]>ans) ans = a[i]&a[j];
            }
        }
    }*/
    cout<<ans;
    return 0;
}
