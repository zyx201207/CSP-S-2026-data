#include<bits/stdc++.h>
#define forUp(i,a,b) for(int i=(a);i<=(b);++i)
#define forUP(i,a,b) for(int i=(a);i<(b);++i)
#define forDown(i,a,b) for(int i=(a);i>=(b);--i)
using int64=long long;
constexpr int N=5e5+10;using namespace std;
int n,ans=1;int64 V,A[N];
void solve(int test_id){
    cin>>n>>V;
    forUp(i,1,n)cin>>A[i];sort(A+1,A+n+1);
    int l=1;int64 sum=0;forUp(r,2,n){
        sum+=(r-l)*(A[r]-A[r-1]);
        while(sum>V)sum-=A[r]-A[l++];
        ans=max(ans,r-l+1);
    }
    cout<<ans<<'\n';
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int test_num=1;
    //cin>>T;
    forUp(test_id,1,test_num)solve(test_id);
    return 0;
}