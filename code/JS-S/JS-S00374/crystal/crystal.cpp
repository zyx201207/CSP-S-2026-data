#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef long long ll;
long long a[N],jl[N],p[N],n,m;
bool check(int x){
    for(int i=x;i<=n;i++){
        ll pyl=a[n]-a[i];
        ll xz=p[i]-p[i-x]-pyl*x;
        if(xz<=m){
            return 1;
        }
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        jl[i]=a[n]-a[i];
        p[i]=p[i-1]+jl[i];
    }
    long long l=0,r=n,mid;
    while(l<r){
        mid=(l+r)/2;
        if(check(mid)){
            l=mid+1;
        }else{
            r=mid;
        }
    }
    cout<<l-1<<'\n';
    return 0;
}
