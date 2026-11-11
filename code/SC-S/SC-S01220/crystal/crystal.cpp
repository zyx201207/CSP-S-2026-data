#include<bits/stdc++.h>
using namespace std;
using i64=long long;
template<class T>
void Cmax(T &x,const T& y){ x=(x<y?y:x); }
const int N=5e5+5;
int n,ans;
i64 a[N],m;
int main(){
    freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+n+1);
    i64 sum=0;
    for(int l=1,r=2;r<=n;++r){
        sum+=(r-l)*(a[r]-a[r-1]);
        while(sum>m) sum-=(a[r]-a[l++]);
        Cmax(ans,r-l+1);
    }
    printf("%d\n",ans);
    fclose(stdin),fclose(stdout);
    return 0;
}