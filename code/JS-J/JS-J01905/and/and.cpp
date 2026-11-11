#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[200005],m,s[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    s[1]=a[1];
    if(m==1){
        cout<<a[n];
        return 0;
    }if(m==n){
        cout<<s[n];
        return 0;
    }if(m==2){
        ll maxn=0;
        for(int i=2;i<=n;i++){
            maxn=max(maxn,a[i]&a[i-1]);
        }cout<<maxn;return 0;
    }ll maxn=0;
    for(int i=1;i<=n-m+1;i++){
        ll s=a[i];
        for(int j=i;j<=i+m-1;j++){
            s&=a[j];
        }maxn=max(maxn,s);
    }cout<<maxn;
    return 0;
}

