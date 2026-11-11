#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,a[N],sm[N],m;
bool check(int mid){
    //[i-mid+1,i]
    for(int i=mid;i<=n;i++){
        //cerr<<i<<" "<<a[i]*mid-(sm[i]-)
        if(a[i]*mid-(sm[i]-sm[i-mid+1-1])<=m){
            return 1;
        }
    }return 0;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",a+i);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sm[i]=sm[i-1]+a[i];
    }
    int l=0,r=N,res=0;
    while(l<=r){
        int mid=l+r>>1;
        if(check(mid)){
            l=mid+1;
            res=mid;
        } else{
            r=mid-1;
        }
    }
    printf("%lld\n",res);
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
