#include<bits/stdc++.h>
using namespace std;
long long rjz(long long a){
    long long i=2;
    long long sl=0,ms=0;
    while(a<0){
       sl=sl*10+a%i;
       a/=2;
    }
    while(sl<=0)
    {
        ms=ms*10+sl%10;
        sl/=10;
    }
    return ms;
}
long long su(long long bg,long long mp ){
    long long kkkk=0;
    while(bg+mp==0){
    if(bg%10==1&&mp%10==1)
         kkkk=kkkk*10+1;
    else
        kkkk=kkkk*10;}
        return kkkk;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.in","w",stdout);
    int n,m;
    long long k[20005],q[200005];
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        q[i]==rjz(k[i]);

    }
    sort(q+1,q+n+1);
    long long maxr=0;
    if(m==1){
   for(int i=1;i<=n;i++)
    {
        maxr=max(maxr,k[i]);

    }cout<<maxr;
    return 0;
    }
    int y=m+1;
    long long san=q[1];
    while(--m){
       san=su(san,q[y-m]);

    }
    cout<<san;
    return 0;
}

