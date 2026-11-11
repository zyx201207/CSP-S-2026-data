#include <bits/stdc++.h>
using namespace std;
long long  a[500005],
     b[500005];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);

    for(int i = 1;i<=n;i++){
        b[i] = a[i+1]-a[i];
    }

    long long dijig = 1;
    while(1){
        if(m-b[dijig]>=0) m-=b[dijig];
        else break;
        dijig++;
    }
    cout<<dijig;



}
