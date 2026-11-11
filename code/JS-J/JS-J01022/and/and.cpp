#pragma GCC optimize(3,"Ofast")
#include<bits/stdc++.h>
using namespace std;
//#define int long long
//mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=2e5+5;
int n,m,a[N],ans,stk[N],top;
multiset<int>st;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        st.insert(a[i]);
    }
    for(int i=29;i>=0 && !st.empty();i--){
        int cnt=0;
        for(int j:st){
            if((j>>i)&1){
                cnt++;
            }
        }
        if(cnt<m)continue;
        ans+=(1<<i);
        set<int>era;
        for(int j:st){
            if(!((j>>i)&1)){
                //why Segmentation Fault!!!???
                //st.erase(j);
                //so slow
                //era.insert(j);
                stk[++top]=j;
            }
        }
        for(int j=1;j<=top;j++){
            st.erase(stk[j]);
        }
    }printf("%d\n",ans);
}
