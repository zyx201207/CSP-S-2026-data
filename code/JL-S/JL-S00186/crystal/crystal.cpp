#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,ans;
int a[N];
bool bj=0,zbj=0;
int fd(int x){
    int num=m,lj=1;
    for(int i=x-1;i>=1;i--){
        if(num<a[x]-a[i]){
            return lj;
        }
        lj++;
        num-=(a[x]-a[i]);
    }
    bj=1;
    return x;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i)zbj=1;
    }
    if(zbj==0){
        int lj=0;
        for(int i=1;i<=n;i++){
            if(lj+i>m){
                cout<<i;
                return 0;
            }
            lj+=i;  
        }
    }
    sort(a+1,a+1+n);
    for(int i=n;i>=1;i--){
        if(a[i]==a[i+1]&&i!=n)continue;
        ans=max(ans,fd(i));
        if(bj==1){
            cout<<ans;
            return 0;
        }
    }
    cout<<ans;
    return 0;
}

