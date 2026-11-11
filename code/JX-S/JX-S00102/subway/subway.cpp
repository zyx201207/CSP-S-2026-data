#include<bits/stdc++.h>
using namespace std;
long long c,k,d,q,n,m,maxs,ttt,a[500005],s[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){scanf("%lld",&ttt);maxs+=ttt;}
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=2*k;j++){scanf("%lld",&ttt);maxs+=ttt;}
    }
    for(int i=1;i<=q;i++)cout<<maxs<<" ";
    return 0;
}

