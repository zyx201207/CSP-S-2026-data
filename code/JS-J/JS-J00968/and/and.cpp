#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=200005;
int a[maxn];
bool checkB(int n){
    for(int i=1;i<=n;i++){
        if(a[i]!=i-1)
            return false;
    }
    return true;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n<=20){
        int ans=0;
        for(int mask=1;mask<(1<<n);mask++){
            if(__builtin_popcount(mask)!=m)
                continue;
            vector<int> res;
            for(int i=1;i<=n;i++){
                if(mask&(1<<(i-1))){
                    res.push_back(a[i]);
                }
            }
            for(int i=1;i<res.size();i++)
                res[0]&=res[i];
            ans=max(ans,res[0]);
        }
        cout<<ans<<endl;
    }
    else if(m==1){
        sort(a+1,a+n+1);
        cout<<a[n]<<endl;
    }
    else if(m==n){
        for(int i=2;i<=n;i++)
            a[1]&=a[i];
        cout<<a[1]<<endl;
    }
    else if(checkB(n)){
        int k=__lg(n+1)-1,cur=0;
        while((1<<cur)<m)
            cur++;
        int cnt=k-cur,ans=0;
        for(int i=0;i<=cnt;i++){
            ans+=(1<<k);
            k--;
        }
        cout<<ans<<endl;
    }
    else{
        sort(a+1,a+n+1,greater<int>());
        cout<<a[m]<<endl;
    }
    return 0;
}
