#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,v[m],a[10000],q,sum;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<=m;i++){
        cin>>a[m];
    }
    cout<<c+n+m+d+q;
    fclose("subway.in");
    fclose("subway.out");
    return 0;
}
