#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,m;
long long a[N];
long long maxn=-1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    if(m==1){
        for(int i=1;i<=n;i++) maxn=max(maxn,a[i]);
        cout<<maxn;
        return 0;
    }
    if(m==n){
        int ans=a[1];
        for(int i=2;i<=n;i++){
            ans&=a[i];
        }
        cout<<ans;
        return 0;
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                maxn=max(maxn,a[i]&=a[j]);
            }
        }
        cout<<maxn;
        return 0;
    }
}

