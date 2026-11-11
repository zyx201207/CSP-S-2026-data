#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,m;
long long a[maxn];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    long long t=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        t=max(t,a[i]);
    }
    long long ans=0;
    if(m==1){
        cout<<t;
        return 0;
    }
    if(m==2){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
    }

    cout<<ans;
    return 0;
}
//Hello JX xing wei da shang
//This is my last to join the CSP-J
//I hope rp++
//wang hou kan you cai dan
