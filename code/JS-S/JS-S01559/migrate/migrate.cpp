#include<bits/stdc++.h>
using namespace std;
long long c,t,n,x[2000005],d,num;
long long fly(long long s,long long e,long long l){
    if(s==e)return 1;
    if(l==0)return 0;
    long long h=0;
    for(long long i=s+1;i<=e&&x[i]-x[s]<=d;i++){
        h+=fly(i,e,l-1);
    }
    return h;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int ti=1;ti<=t;ti++){
        cin>>n>>d;
        num=0;
        for(long long i=1;i<=n;i++){
            cin>>x[i];
            for(long long j=1;x[i]-x[j]>d;j++)num+=fly(j,i,(x[i]-x[j])/d+((x[i]-x[j])%d>0))==2;
        }
        cout<<num;
    }
    return 0;
}
