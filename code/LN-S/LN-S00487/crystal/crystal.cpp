#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int m,n,p[50005],MAX[50005],MIN[50005],new_min[30005],new_max[30005],a,b;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        cin>>p[i];
        if(i==0)a=p[i],b=p[i];
        else{
            a=min(p[i],a),b=max(p[i],b);
        }
    }
    for(int j=0;j<m;j++){
        if(a!=p[j]){
            MIN[j]=p[j]-a;
        }
        if(b!=p[j]){
            MAX[j]=p[j]-b;
        }
    }
    for(int k=0;k<m;k++){

    }
    int mp=0,jm=0;
    for(int g=0;g<m;g++){
        if(MAX[g]>=-n){
            new_max[g]=MAX[g],mp++;
        }
        if(MIN[g]<=n){
            new_min[g]=MIN[g],jm++;
        }
    }
    int umax,umin,r1,r2,sb=0,lo=0;
    for(int z=0;z<jm;z++)sb+=new_min[z];
    for(int x=0;x<mp;x++)lo+=new_max[x];
    if(n>=sb)umin=jm;
    else{
        umin=jm-1;
    }
    if(-n<=lo)umax=mp;
    else{
        umin=jm-1;
    }
    cout<<max(umin,umax);
    return 0;
}
