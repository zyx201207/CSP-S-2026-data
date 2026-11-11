#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[2005];
int maxx=-1;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==n){
        int sum=a[1];
        for(int i=2;i<=n;i++){
            sum&=a[i];
        }
        cout<<sum;
        return 0;
    }
    if(m==1){
        int maxx=-1;
        for(int i=1;i<=n;i++){
            maxx=max(maxx,a[i]);
        }
        cout<<maxx;
        return 0;
    }
    if(m==2){
        int maxxx=-1;
        int t=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                t=a[i];
                t&=a[j];
                maxx=max(maxxx,t);
            }
        }
        cout<<maxxx;
        return 0;
    }
}
