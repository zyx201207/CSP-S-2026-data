#include <bits/stdc++.h>
using namespace std;
int n,a[200001],m;
int ans;
int main(){
    freopen("ans.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    if(m==1)
        ans=10;
    else
        if(m==n){
            int ans=a[1];
            for(int i=1;i<=n;i++)
                ans&=a[i];
        }
        else
            if(m==2){
                for(int i=1;i<=n;i++)
                    for(int j=1;j<=n;j++){
                        if(j!=i)
                            ans=max(a[i]&a[j],ans);
                    }
            }
    printf("%d",ans);
}
