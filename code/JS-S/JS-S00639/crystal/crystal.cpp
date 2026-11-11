#include<bits/stdc++.h>
#define Maxn 100010
#define LL long long
using namespace std;
int n,ans=1;
LL m;
LL a[Maxn];
bool y=true;
void free(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
}
int main(){
    free();
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2])y=false;
    }
    if(y==true){
        for(int i=1;i<n;i++){
            m=m-abs(a[2]-a[1])*(LL)i;
            if(m>=0)ans++;
            else break;
        }
        printf("%d",ans);
        return 0;
    }
    sort(a+1,a+n+1);
    int x=0;
    LL k=m;
    for(int i=2;i<=n;i++){
        x=1;m=k;
        for(int j=1;j<i;j++){
            m=m-(a[j+1]-a[j])*(LL)j;
            if(m<0)break;
            x++;
        }
        ans=max(ans,x);
    }
    printf("%d",ans);
    return 0;
}
