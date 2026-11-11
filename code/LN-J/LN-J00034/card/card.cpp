#include<bits/stdc++.h>
using namespace std;
int n,mid,l=1,i=1,r,ll=1,rr,a[200200];
long long ans;
char c[200200];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(;i<=n;i++) scanf("%d %c",&a[i],&c[i]);
    rr=n;
    while(ll<rr){
        if(a[ll]==0) ll++;
        if(a[rr]==0) rr--;
        if(c[ll]!=c[rr]) ans+=min(a[ll],a[rr]);
        if(a[ll]<=a[rr]) a[rr]-=a[ll],a[ll]=0;
        else a[ll]-=a[rr],a[rr]=0;
    }cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
