#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005],x=1,n,m,b[500005],c[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[a[i]]++;
        c[a[i]]=i;
    }
    for(int i=1;i<=n;i++){

    }

    fclose(stdin);
    fclose(stdout);
    return 0;

}
