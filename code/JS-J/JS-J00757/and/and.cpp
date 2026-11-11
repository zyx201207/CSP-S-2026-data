#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
ll a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(m==n){
        ll cnt=LONG_MAX;
        for(int i=1;i<=n;i++){
            cnt&=a[i];
        }
        cout<<cnt;
    }
    else if(m==1) {
        cout<<a[n];
    }
    else if(m==2){
        cout<<(a[n-1]&a[n]);
    }
    else if(m=n-1){
        ll cnt=LONG_MAX;
        for(int i=2;i<=n;i++){
            cnt&=a[i];
        }
        cout<<cnt;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

