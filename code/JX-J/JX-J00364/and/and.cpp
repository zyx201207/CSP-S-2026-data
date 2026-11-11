#include<bits/stdc++.h>
using namespace std;
int a[200005];
int ans[200005];
int ans1[200005];
int cnt[200005];
int cnt1[200005];
int n,m;
int maxn,t;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans[i]=a[i]%2;
        a[i]=a[i]/2;
        ans1[i]=ans[i];
        ans[i]=0;
        if(ans[i]==1&&ans1[i]==1){
            cnt[i]=1;
        }else if(ans[i]==1&&ans1[i]==0||ans[i]==0&&ans1[i]==1){
            cnt[i]=0;
        }else if(ans[i]==0&&ans1[i]==0){
            cnt[i]=0;
        }
    }
    for(int i=1;i<=n;i++){
        if(cnt[i]==1){
            long long x=1;
            if(i==0){
                x=0;
            }else{
                while(i--){
                    x*=2;
                }
            }
            t+=i*x;
        }else{
            t+=0;
        }
        maxn=max(maxn,t);
    }
    cout<<maxn;
    return 0;
}
