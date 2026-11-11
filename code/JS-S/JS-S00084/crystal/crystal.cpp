#include <bits/stdc++.h>
using namespace std;

const int N=5e5+5;

typedef long long ll;
typedef unsigned long long ull;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define rf(i,a,b) for(int i=(a);i>=(b);--i)
#define max_eq(a,b) ((a)=(a)>(b)? (a):(b))
#define min_eq(a,b) ((a)=(a)<(b)? (a):(b))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(),(x).end()

int n;
ll a[N],s[N],m;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    F(i,1,n) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    F(i,1,n) s[i]=s[i-1]+a[i];
    int ans=1;
    F(i,1,n){
        int L=1,R=i,res=i;
        while(L<=R){
            int mid=(L+R)/2;
            if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m) res=mid, R=mid-1;
            else L=mid+1;
        }
        ans=max(ans,i-res+1);
    }
    printf("%d\n",ans);
    return 0;
}


// g++ crystal.cpp -o crystal -std=c++14 -O2 -Wall -Wextra -Wshadow -Wconversion -fsanitize=address,undefined
// ulimit -s 524288
// /usr/bin/time -v ./my
// g++ my.cpp -o my -std=c++14 -O2 -Wall