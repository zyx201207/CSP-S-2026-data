#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);    
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a,a+n);
    for(int i=2;i<=n;i++){
        long long cha=0,shu=1;
        for(int j=i-1;j>=1;j--){
            cha+=a[i]-a[j];
            if(cha>m)break;
            shu++;
        }ans=max(ans,shu);
    }cout<<ans;
    return 0;
}
