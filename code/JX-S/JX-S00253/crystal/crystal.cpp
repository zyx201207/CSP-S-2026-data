#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1010101],ans=1;
long long d[4010101],tag[4010011];
void chang(long long s,long long t,long long l,long long r,long long a2,long long p){
    if(s>=l&t<=r){
        d[p]+=(t-s+1)*a2;
        tag[p]+=a2;
        return;
    }
    long long mid=(s+t)/2;
    if(mid>=l){
        chang(s,mid,l,r,a2,p*2);
    }
    if(mid<r){
        chang(mid+1,t,l,r,a2,p*2+1);
    }
    d[p]=d[p*2]+d[p*2+1];
}
long long getsum(long long s,long long t,long long l,long long r,long long p){
    if(s>=l&&t<=r){
        return d[p];
    }
    long long mid=(s+t)/2,fans=0;
    if(tag[p]){
        tag[p*2]+=tag[p];
        d[p*2]+=(mid-s+1)*tag[p];
        tag[p*2+1]+=tag[p];
        d[p*2+1]+=(t-(mid+1)+1)*tag[p];
        tag[p]=0;
    }
    if(mid>=l){
        fans+=getsum(s,mid,l,r,p*2);
    }
    if(mid<r){
        fans+=getsum(mid+1,t,l,r,p*2+1);
    }
    d[p]=d[p*2]+d[p*2+1];
    return fans;
}
long long erfen(long long u){
    long long s=1,t=u-1;
    while(1){
        if(s==t){
            return u-s+1;
        }
        long long mid=getsum(1,n,(s+t)/2,u-1,1);
        if(mid<=m){
            t=(s+t)/2;
        }else{
            s=((s+t)/2)+1;
        }
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        chang(1,n,1,i-1,a[i]-a[i-1],1);
        //for(int j=1;j<i;j++){
        //    cout<<getsum(1,n,j,j,1)<<" ";
        //}
        //cout<<"\n";
        ans=max(ans,erfen(i));
    }
    cout<<ans;
    return 0;
}

