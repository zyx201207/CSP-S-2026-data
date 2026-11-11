#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m,n,i,j,a[500010],b[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>a[i];
        for(j=0;j<i;j++){
            b[i]+=a[i]-a[j];
        }
        if(m<b[i])break;
    }
    cout<<i;
    return 0;
}
