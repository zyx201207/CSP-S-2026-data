#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    long long n,m,maxn=-1,num=1,last=1,remain,a[500005];
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    remain=m;
    for(long long i=2;i<=n;i++){
        remain-=num*(a[i]-a[i-1]);
        while(remain<0){
            num--;
            remain+=a[i]-a[last];
            last++;
        }
        num++;
        maxn=max(maxn,num);
    }
    cout<<maxn;

    return 0;
}
