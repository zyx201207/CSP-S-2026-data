#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int n,ans=1;
long long m;
bool check(long long t){
    int i=n;
    if(a[1]>t){
        return true;
    }
    while(a[i]>t){
        i--;
    }
    long long tm=m;
    if(tm<t-a[i])return false;
    int res=0;
    while(tm>=t-a[i]&&i>0){
        res++;
        tm-=(t-a[i]);
        i--;
    }
    bool tt=(res<=ans);
    ans=max(ans,res);
    return tt;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long l=1,r=m;
    while(l<r-1){
        long long mid=(l+r)/2;
        if(check(mid)){
            l=mid;
        }else{
            r=mid-1;
        }
    }
    check(l);
    check(r);
    cout<<ans<<endl;
    return 0;
}
