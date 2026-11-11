#include <bits/stdc++.h>
using namespace std;
long long x,y,a[1000000],ans;
vector<pair<long long ,int>>v;
int main(){
   freopen("crystal.in","r",stdin);
   freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&x,&y);
    for(int i=0;i<x;i++){
        scanf("%lld",&a[i]);
    }
    sort(a,a+x);
    long long l=0,zh=0;
    for(int i=0;i<x;i++){
        while((i-l)*a[i]-zh>y){
            zh-=a[l];
            l++;
        }
        ans=max((i-l+1),ans);
        zh+=a[i];
    }
    printf("%lld",ans);
    return 0;
}
