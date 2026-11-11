#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N=2e6+10;
ll a[N],t[N],l[N],r[N];
ll d;

bool ck(int l,int r){
    ll cnt=0,lst=0;
    bool f=false;
    for(int i=l;i<r;i++){
        if(a[i+1]-a[i]>d)return false;
        if(i+3<=r&&a[i+3]-a[i]<=d)return false;
        if(lst==1&&a[i+2]-a[i]<=d&&i+2<=r)f=true;
        if(a[i+2]-a[i]<=d&&i+2<=r)lst=1,cnt++;
        if(cnt>2)return false;
    }
    return f;
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--){
        ll n;
        cin>>n>>d;
        bool flag=true;
        for(int i=1;i<=n;i++)cin>>a[i];
        sort(a+1,a+1+n);
        for(int i=3;i<=n;i++)if(a[i]-a[i-1]!=a[2]-a[1])flag=false;
        if(flag){
            if(a[2]-a[1]>2*d)cout<<0<<'\n';
            else cout<<n-3<<'\n';
        }
        else{
            int cnt=0;
            for(int i=1;i<=n;i++)for(int j=i+3;j<=n;j++)cnt+=ck(i,j);
            cout<<cnt<<'\n';
        }
    }
    return 0;
}
