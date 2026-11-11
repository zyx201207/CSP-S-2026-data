#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long s[500005];
bool check(int mid,int id){
    int len=id-mid+1;
    long long t=a[id]*len;
    return ((t-s[id]+s[mid-1])<=m);
}
int bs(int l,int r,int id){
    if(l>=r) return l;
    int mid=(l+r)>>1;
    if(check(mid,id)){
        return bs(l,mid,id);
    }
    else{
        return bs(mid+1,r,id);
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    int maxn=0;
    for(int i=1;i<=n;i++){
        maxn=max(maxn,i+1-bs(1,i,i));
    }
    cout<<maxn;
    return 0;
}
