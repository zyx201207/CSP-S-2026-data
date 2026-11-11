#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005]=0,x,max1=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x;
        a[x]++;
    }
    for(long long i=1;i<=200005;i++){
        if(a[i]>=1){
            max1=max(max1,i);
        }
    }
    cout<<max1;
    return 0;
}
