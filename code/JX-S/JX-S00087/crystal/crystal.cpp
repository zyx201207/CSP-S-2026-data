#include <iostream>
#include <algorithm>
using namespace std;
const int N = 5e5+10;
const long long M = 1e18;
long long a[N];
long long t_a[N];
long long n,m;
long long ans = 0;
bool cmp(long long v1,long long v2){
    return v1>v2;
}
bool check(long long mid){
    long long sum = 0;
    for(long long i=1;i<=n;i++){
        if(a[i]<=mid){
            sum += mid - a[i];
        }
    }
    return sum<=m;
}
long long ef(long long l,long long r){
    long long mid = (l+r)>>1;
    if(l>r){
        return r;
    }
    if(check(mid)){
        ans = mid;
        return ef(mid+1,r);
    }
    else{
        return ef(l,mid-1);
    }
}

long long erfen(long long l,long long r){
    long long mid = (l+r)>>1;
    if(a[mid] == ans){
        return mid;
    }
    if(l>r){
        return r;
    }
    else{
        if(ans>a[mid]){
            return erfen(mid+1,r);
        }
        else{
            return erfen(l,mid-1);
        }
    }
}

int main(){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    scanf("%lld",&n);
    scanf("%lld",&m);
    long long le = 0;
    long long ri = 0;
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        le = min(le,a[i]);
        ri = max(ri,a[i]);
    }
    sort(a+1,a+n+1);
    long long temp = ef(le,ri);

    long long pos = erfen(1,n);
    while(a[pos] == a[pos+1]){
        pos++;
    }
    printf("%lld",pos);



    return 0;
}
