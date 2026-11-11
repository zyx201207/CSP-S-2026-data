#include<bits/stdc++.h>
using namespace std;
long long qzh[200005],dg[1000005],n,d,pos,ans,pos2;
char c;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>d>>c;
        qzh[i]=qzh[i-1]+d;
        dg[qzh[i]]=int(c);
    }
    for(long long i=1;i<=qzh[n]/2;i++){
        pos=upper_bound(dg+i,dg+qzh[n]/2+1,0)-dg;
        pos2=upper_bound(dg+qzh[n]-i,dg+qzh[n]+1,0)-dg;
        if(dg[pos]!=dg[pos2]) ans++;
    }
    cout<<ans;
    return 0;
}
