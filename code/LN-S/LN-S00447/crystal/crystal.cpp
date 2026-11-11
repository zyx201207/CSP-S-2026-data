#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,a[500005];
    cin>>n>>m;
    long long ji=m,big;//记述值
    for(int i=1;i<=n;i++){
        cin>>a[i];
    };
    sort(a,a+n+1);//从小到大
    if(n==1)
        cout<<1;
    if(n==2&&a[2]-a[1]<=m)
        cout<<2;
    else{
        for(int i=1;i<=n;i++){
        m+=a[i];
        if(m/i==a[i+1]){
            big=i+1;
        }
    }
        cout<<big;}



    return 0;
}
