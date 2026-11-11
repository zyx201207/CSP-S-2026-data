#include<bits/stdc++.h>
using namespace std;
#define int long long
const int A=1e9;
int a[A];
int n,m;
signed main(){
    freopen("crystal.in","r",stdin)
    freopen("crystal.out","w",stdout)
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        cin>>a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int cha=a[i+1]-a[i];
        while(n--){
            int sum=0;
            sum+=cha;
            if(sum==m){
                ans+=1;
            }
            cout<<ans;
        }
    }
    return 0;
}
