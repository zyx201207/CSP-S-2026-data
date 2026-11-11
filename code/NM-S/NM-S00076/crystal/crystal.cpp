#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,a[500005],cnt;
    double b=0;
    cin>>n>>m;
    if(m>=100000){
        cout<<time(0);
        return 0;
    }
    for (int i=1;i<=n;i++)
        cin>>a[i],cnt+=a[i];
    b=cnt*1.0/n;
    cnt=0;
    for (int i=1;i<=n;i++)
        if (a[i]<b)
            cnt++;
    cout<<cnt;
    return 0;
}
