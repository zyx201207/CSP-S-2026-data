#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define de(x...) fprintf(stderr,x)
#define rep(i,l,r) for(auto i = l;i <= r;++i)
#define per(i,l,r) for(auto i = l;i >= r;--i)
const int N = 500005;
int n,A;
ll m,a[N],s[N];
bool chk(int l,int r){
    return a[r] * (r-l+1) - s[r] + s[l-1] <= m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    rep(i,1,n)  scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    rep(i,1,n){
        s[i] = s[i-1] + a[i];
        int l = 1,r = i;
        while(l < r){
            int mid = (l+r)>>1;
            if(chk(mid,i))  r = mid;
            else    l = mid+1;
        }
        A = max(A,i-l+1);
    }
    printf("%d\n",A);
    fclose(stdin);
    fclose(stdout);
    return 0;
}