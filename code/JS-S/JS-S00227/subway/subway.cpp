#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500010]={};long long a[10010][10010]={},t[10010][10010]={};long long startn[500010]={};long long endn[500010]={};
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(long long i=1;i<m+1;i++)
        cin>>w[i];
    for(long long i=1;i<n+1;i++){
        long long ki=0;
        cin>>ki;
        for(int j=1;j<ki+1;j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(long long r=1;r<=q;r++)
        cin>>startn[r]>>endn[r];
    for(long long i=1;i<=q;i++){
        long long ans=0;
        ans=w[startn[i]]+w[endn[i]];
        for(long long j=startn[i];j<endn[i];j++)
            ans=ans+t[i][j]+t[i][j+1];
        cout<<ans-t[startn[i]][endn[i]]<<endl;
    }
    return 0;
}
