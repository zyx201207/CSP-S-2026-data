
#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,m,a[N],l=0,r,b[N];
bool check(int x){
    long long cost,ans=LLONG_MAX;
    for(int i=1;i<=n-x+1;i++){
        cost=a[i+x-1]*x-(b[i+x-1]-b[i-1]);
        ans=min(ans,cost);
    }
    if(ans<=m)return 1;
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    r=n+1;
    a[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+1+n);
    for(int i=1;i<=n;i++){
         b[i]=b[i-1]+a[i];//qianzhuihe
    }
    long long mid;
     while(l<=r){//er fen da an
        mid=(l+r)>>1;
        if(check(mid)){
           // cout<<mid<<" ok "<<"l->"<<mid+1<<'\n';
            l=mid+1;
        }
        else {
            r=mid-1;
           // cout<<"r->"<<mid-1;
        }
    }
    cout<<r;
    return 0;
}

