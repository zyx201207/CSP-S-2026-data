#include<bits/stdc++.h>
using namespace std;
const int N =5e5 +10;
int n,m;
long long a[N];
long long cnt[4];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    long long maxn=0;
    bool A=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(A){
            for(int i=0;i<=30;i++){
                if(a[i]+1!=(1<<i)){
                    A=0;
                    break;
                }
            }
        }
        if(a[i]<4){
            cnt[a[i]]++;
        }
        maxn=max(maxn,a[i]);
    }
    if(m==1){
        cout<<maxn;
        return 0;
    }else if(n==m){
        long long ans=2e30-1;
        for(int i=1;i<=n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }else if(m==2){
        long long ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
        return 0;
    }
    if(A){
        sort(a+1,a+n+1);
        cout<<a[n-m+1];
        return 0;
    }
    if(maxn<4){
        if(m<cnt[3]){
            cout<<3;
        }else if(m<cnt[2]+cnt[3]){
            cout<<2;
        }else if(m<cnt[1]+cnt[2]+cnt[3]){
            cout<<1;
        }else{
            cout<<0;
        }
        return 0;
    }
    long long ans=0;
    for(int i=(1<<m);i<=(1<<(n+1));i++){
        int cnt=0;
        for(int j=0;j<=ceil(log2(i));j++){
            cnt+=(i>>j)&1;
        }
        if(cnt==m){
            long long res=2e30-1;
            for(int j=0;j<=ceil(log2(i));j++){
                if(((i>>j)&1)==1){
                    res=res&a[j];
                }
            }
            ans=max(ans,res);
        }
    }
    cout<<ans;
    return 0;
}
