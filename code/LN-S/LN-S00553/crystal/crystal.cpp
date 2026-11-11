#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
long long n,m,a[MAXN],ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        long long sum=0;
        for(int j=1;j<i;j++){
            sum+=a[i]-a[j];
        }
        if(sum<=m) {
            ans=i;
        }
    }
    cout<<ans;
    return 0;
}
