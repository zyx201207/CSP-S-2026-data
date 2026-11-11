#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
int n,ans;
ll m,a[N],sum[N];
inline bool check(int s,int e){
    ll ned=a[e]*(e-s+1),had=sum[e]-sum[s-1];
    return ned-had<=m;
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;++i){
        sum[i]=sum[i-1]+a[i];
        int l=1,r=i,res=i;
        while(l<=r){
            int mid=l+r>>1;
            if(check(mid,i))r=mid-1,res=mid;
            else l=mid+1;
        }
        ans=max(ans,i-res+1);
    }
    cout<<ans;
    return 0;
}
/*
进行排序
对于当前每一个结尾，都去找一下它所能匹配的最前面那个点->枚举右端点，寻找左端点
前缀和快速求出已有能量
这一段的已有能量与m的和要大于等于所需的才行
开long long!!!
*/
//35min切了
