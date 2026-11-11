#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
long long dg(int l,int r){
    if(l==r)return 0;
    int mi=min(a[l],a[r]);
    int b=0;
    if(mi==a[r])b=1;
    if(c[l]==c[r]){
        if(l+1==r)return 0;
        if(b==0){
            a[r]=(a[r]-a[l]);
            a[l]=0;
            return dg(l+1,r);
        }
        a[l]=(a[l]-a[r]);
        a[r]=0;
        return dg(l,r-1);
    }
    if(l+1==r)return mi;
    if(b==0){
        a[r]=(a[r]-a[l]);
        a[l]=0;
        return (mi+dg(l+1,r));
    }
    a[l]=(a[l]-a[r]);
    a[r]=0;
    return (mi+dg(l,r-1));
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    if(n==1){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    cout<<dg(1,n);
    return 0;
}
