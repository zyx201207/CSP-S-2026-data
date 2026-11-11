#include<bits/stdc++.h>
using namespace std;
long long n,t,sum,ans;
struct node{
        long long c;
        char z;
        long long ks,js;
};
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    t=1;
    node a[200009];
    for(int i=1;i<=n;i++){
        cin>>a[i].c>>a[i].z;
        a[i].ks=t;
        t=t+a[i].c;
        sum+=a[i].c;
        a[i].js=a[i].ks+a[i].c-1;
    }
    long long l=1,r=sum,lj=1,rj=n;
    while(l<r){
        int minn=min(a[lj].js-l+1,r-a[rj].ks+1);
        if(l>a[lj].js){
            lj++;
        }
        if(r<a[rj].ks){
            rj--;
        }
        if(a[lj].z!=a[rj].z){
            ans+=minn;
            l+=minn;
            r-=minn;
        }
        else{
            l+=minn;
            r-=minn;
        }
    }
    cout<<ans;
    return 0;
}
