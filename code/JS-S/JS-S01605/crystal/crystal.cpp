#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],cnt=0,cf[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    bool f=0;
    for(int i=2;i<=n;i++){
        if(a[i]!=a[i-1]){
            f=1;
            break;
        }
    }
    if(!f){
        cout<<n;
        return 0;
    }
    if(m==0){
        long long t[100005],mx=-1;
        for(int i=1;i<=n;i++){
            t[a[i]]++;
            mx=max(mx,t[a[i]]);
        }
        cout<<mx;
        return 0;
    }
    if(n>5000&&n<=500005&&m<100000000&&m<=1000000000000000000){
        for(int i=1;i<=n;i++){
            if(m<a[i])break;
            m-=a[i];
            cnt++;
            cout<<cnt;
        }
        return 0;
    }
    for(int i=2;i<=n;i++)cf[i]=cf[i-1]+(a[i]-a[i-1]);
    for(int i=1;i<n;i++){
        if(m<cf[i])break;
        cnt++;
    }
    cout<<cnt;
    return 0;
}