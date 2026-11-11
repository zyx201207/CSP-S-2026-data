
#include <bits/stdc++.h>

using namespace std;

int n,m;
int b[32];

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int a;
        scanf("%d",&a);
        int j=0;
        while(a){
            b[j]+=a%2;
            a/=2;
            j++;
        }
    }
    //////
    int ans=0;
    for(int i=31;i>=0;i--){
        if(b[i]>=m){
            ans+=pow(2,i);
        }
    }
    printf("%d",ans);
    return 0;
}
