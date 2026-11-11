#include <bits/stdc++.h>
using namespace std;

bool cmp(long x,long y){
    return x<y;
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    long n,m,a[500005]={},p[500005]={};
    cin>>n>>m;
    for(int i=1;i<=n;i++){
            cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    long maxx=-1e9,maxdex=0;
    for(int i=1;i<=n;i++){
        p[i]=a[i]-a[i-1];
        if(p[i]>maxx){
            maxx=a[i];
            maxdex=i;
        }
    }

    while(m>0){
        if(m>=p[maxdex-1]){
            m-=p[maxdex-1];
            p[maxdex-1-1]+=p[maxdex-1];
            p[maxdex-1]=0;
            maxdex--;
        }
        else break;
    }
    int cnt=1;
    for(int i=1;i<=n;i++){
        if(p[i]==0) cnt++;
    }
    cout<<cnt;
    return 0;
}