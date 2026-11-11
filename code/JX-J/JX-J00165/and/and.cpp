#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[1009897];
int ans=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int j=i;
        int f=m;
        int sum=a[j];
        while(f--&&j<=n){
            j++;
            sum&=a[j];
        }
        ans=max(sum,ans);
    }
    cout<<ans;
    return 0;
}
