#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m,sum=0,cnt=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1)sum++;
        if(a[i]==2)cnt++;
    }
    if(m==1){
        cout<<n;
        return 0;
    }
    if(m==2){
        cout<<sum<<' '<<cnt;
        return 0;
    }
    for(int i=1;i<=m ;i++){
        cout<<a[i]<<' ';
    }
}

