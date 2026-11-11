#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==1){
        cout<<1;
        return 0;
    }
    sort(a,a+n);
    int ans=0;
    for(int i=0;i<n;i++){
        int tmp=m;
        int amp=1;
        for(int j=i-1;j>=0;j--){
            if(a[i]-a[j]<=tmp){
                tmp-=a[i]-a[j];
                amp++;
            }
            else{
                break;
            }
        }
        ans=max(ans,amp);
    }
    cout<<ans;
    return 0;
}
