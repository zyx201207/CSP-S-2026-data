#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],sum=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    if(m==0) cout<<1<<endl;
    if(n==1) cout<<1<<endl;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    int minn=a[1];
    for(int i=1;i<=m;i++){
        a[1]++;
        sort(a+1,a+1+n);
    }
    int k=a[1];
    for(int i=2;i<=n;i++){
        sum++;
        if(k!=a[i]) break;
    }
    cout<<sum<<endl;
    return 0;
}
