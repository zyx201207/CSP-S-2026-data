#include<bits/stdc++.h>
using std::sort;
using std::greater;
int n , m , a[200200] ;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1,greater<int>());
    int ans=0;
    for(int bit=30;bit>=0;bit--){
        if(((a[m]>>bit)&1)==1){
            ans+=(1<<bit);
            for(int i=1;i<=n;i++){
                if(a[i]<(1<<bit)){
                    n=i-1;
                    break;
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(a[i]>=(1<<bit)) a[i]-=(1<<bit);
        }
        sort(a+1,a+n+1,greater<int>());
    }
    printf("%d",ans);
    return 0;
}
