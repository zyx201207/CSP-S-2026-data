#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=5e5+10;
int a[N];
int b[N];

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1ll,a+n+1ll);
    for(int i=2;i<=n;i++){
        b[i]=a[i]-a[i-1ll];
    }
    int cost=0;
    int lft=1;
    int ans=1;
    int len=1;
    for(int i=2;i<=n;i++){
        cost+=len*b[i];
        len++;
        if(cost<=m){
            ans=max(ans,len);
        }
        else{
            while(cost>m){
                if(len==0){
                    cost=0;
                    break;
                }
                cost-=b[i]-b[lft];
                lft++;
                len--;
            }
        }
    }
    cout<<ans;
    return 0;
}
