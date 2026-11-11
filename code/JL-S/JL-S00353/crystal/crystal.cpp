#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int m,n,cnt,c,a[1000005],sum;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];

    }
    c=(a[1]+a[n])/2+1;
    for(int i=1;i<=n;i++){
        if(a[i]<=c){
            sum=c-a[i];
            cnt++;
        }
        if(i==n&&sum>m){
            i=1;
            sum=0;
            cnt=0;
            c-=1;
        }

    }
    cout<<cnt;
    return 0;
}
