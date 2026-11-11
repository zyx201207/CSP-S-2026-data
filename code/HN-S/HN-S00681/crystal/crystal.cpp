#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,l=1e18,r=-1e18,ans,a[N];
inline int read(){
    int sum=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        sum=sum*10+ch-'0';
        ch=getchar();
    }
    return sum*f;
}
int check(int x){
    int it=upper_bound(a+1,a+n+1,x)-a-1;
    int cnt=0,res=0;
    for(int i=it;i>=1;i--){
        int num=x-a[i];
        if(cnt+num<=m){
            cnt+=num;
            res++;
        }
    }
   // cout<<x<<" "<<res<<"\n";
    return res;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        l=min(l,a[i]);
        r=max(r,a[i]);
    }
    sort(a+1,a+n+1);
    // for(int i=1;i<=n;i++){
    //     s[i]=s[i-1]+a[i];
    // }
    //cout<<l<<" "<<r<<"\n";
    while(l<=r){
        int mid=(l+r)/2;
        int res=check(mid);
        if(res>=ans){
            ans=max(ans,res);
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
//Oct31==Dec25?
/*
5 8
-3 -1 2 2 7

5 5
1 2 4 8 9
*/