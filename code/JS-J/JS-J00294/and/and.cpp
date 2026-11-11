#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int n,m;
int baoli(int ald,int pos,int ans){
    if(ald>=m)return ans;
    if(pos>=n)return 0;
    int tmp=INT_MIN;
    for(int i = pos+1;i<=n;i++){
        tmp=max(tmp,baoli(ald+1,i,ans&a[i]));
    }
    return tmp;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int maxn=INT_MIN;
    int minn=INT_MAX;
    int tmp=INT_MAX;
    bool ok=true;
    for(int i = 1;i<=n;i++){
            cin>>a[i];
            maxn=max(maxn,a[i]);
            minn=min(minn,a[i]);
            tmp=tmp&a[i];
            if(a[i]!=(i-1))ok=false;
    }
    if(n<=20){
        int ans=INT_MIN;
        for(int i = 1;i<=n-m+1;i++){
            ans=max(ans,baoli(1,i,a[i]));
        }
        cout<<ans;
        return 0;
    }
    else if(n<=2000){
        if(m==1){
            cout<<maxn;
            return 0;
        }
        else if(m==2){
            int ans=INT_MIN;
            for(int i = 1;i<=n;i++){
                for(int j = i+1;j<=n;j++){
                    ans=max(ans,a[i]&a[j]);
                }
            }
            cout<<ans;
            return 0;
        }
        else if(m==n){
            cout<<tmp;
            return 0;
        }
    }
    else{
        if(ok){
            cout<<n-m;
            return 0;
        }
        else if(m==2){
            int ans=INT_MIN;
            for(int i = 1;i<=n;i++){
                for(int j = i+1;j<=n;j++){
                    ans=max(ans,a[i]&a[j]);
                }
            }
            cout<<ans;
            return 0;
        }
        cout<<minn;
        return 0;
    }
}
