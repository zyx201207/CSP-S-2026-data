#include<bits/stdc++.h>
using namespace std;
int n;
long long m ,a[500005],b[500005],ans,ls[500005];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
  }

    sort (a+1,a+n+1);

    cout<<(n/2+1);
    return 0;
}
