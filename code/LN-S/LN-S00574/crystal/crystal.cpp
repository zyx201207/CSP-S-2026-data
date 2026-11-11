#include <bits/stdc++.h>
using namespace std;
long long m,a[500001],maxa=0;
int n,ans=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
        maxa=max(a[i],maxa);
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        if(a[i]==a[i+1])continue;
        int ans1=0;
        long long b=m;
        for(int j=i;b>0&&j>=0;j--){
            ans1++;
            b-=a[i]-a[j];
        }
        if(b<0)ans1--;
        ans=max(ans,ans1);
    }
    printf("%d",ans);
    return 0;
}
