#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


const int N=2e5+5;
int n,m;
int a[N];
ll ans,maxn;

bool check(){
    int x=n;
    bool flag=false;
    while(x%2==0&&x>=2){
        if(x==2) {
            flag=true;
        }
        x/=2;
    }
    return flag;
}

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    bool f=true;;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=4) f=false;
    }
    if(n<=2000){
        for(int i=1;i<=n;i++){
            ll tp=a[i];
            for(int j=1;j<=m;j++){
                ll tp1=tp;
                for(int k=1;k<=n;k++){
                    if(maxn==k) continue;
                    if(tp1<tp&a[k]){
                        tp1=tp&a[k];
                        maxn=k;
                    }
                }
                tp=tp1;
            }
            ans=max(ans,tp);

        }
    }else if(m=n-1){
        sort(a+1,a+1+n);
        ans=a[2];
        for(int i=2;i<=n;i++){
            ans&=a[i];
        }
    }else if(check()){
        ans=a[n-1];
        int x=n;
        while(m--){
            ans&=a[x];
            x=x/2-1;
        }
    }else if(f){
        cout<<4;
        return 0;
    }
    else{
        sort(a+1,a+1+n);
        ans=a[n];
        for(int i=n;i>=n-m;i--){
            ans&=a[i];
        }
    }
    cout<<ans;


    return 0;
}







