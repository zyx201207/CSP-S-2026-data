#include<bits/stdc++.h>
using namespace std;
const int N=500010;
long long n,m,m1,a[N],v[N],x=LONG_MIN,p;
long long q,ans;
int Finds(long long x){
    int w,r=1,l=n;
    while(w!=x){
        if(a[r+(l-r)/2]==x) return (l-r)/2;
        if(a[(r+l-r)/2]>x){
            l-=r+(l-r)/2;
        }else{
            r+=r+(l-r)/2;
        }
    }
    if(a[l]-q>=a[r]-q) return a[r];
    return a[l];
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    m1=m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        q+=a[i];
    }
    sort(a+1,a+n+1);
    q/=n;

    while(m){
        for(int i=1;i<n;i++){
            v[i]=a[i+1]-a[i];
        }
        p=Finds(q);
        for(int i=1;i<=p;i++){
            v[i]=q-a[i];
        }
        for(int i=p;i>=1;i--){
            long long v1=v[i];
            m-=v[i];
            v[i]=v1-(m1-m);
        }
    }
    for(int i=1;i<=n;i++){
        if(v[i]==0){
            ans++;
        }
    }
    cout<<ans+1;
    return 0;
}
