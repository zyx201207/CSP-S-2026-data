#include <bits/stdc++.h>
using namespace std;
int n,a[2][200000];
char c[2][200000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    long long L=0,ans=0;
    for(int i=0;i<n;i++){
        scanf("%d %c",&a[0][i],&c[0][i]);
        L+=a[0][i];
        a[1][n-i-1]=a[0][i];
        c[1][n-i-1]=c[0][i];
    }
    long long i1=0,j1=0,i2=0,j2=0;
    for(;i2<L/2&&j2<L/2;){
        if(c[0][i1]!=c[1][j1]){
            ans+=min(j2+a[1][j1],i2+a[0][i1])-max(j2,i2);
        }
        bool b=0;
        if(j2+a[1][j1]>=i2+a[0][i1])b=1;
        if(j2+a[1][j1]<=i2+a[0][i1]){
            j2+=a[1][j1];
            j1++;
        }
        if(b){
            i2+=a[0][i1];
            i1++;
        }
    }
    printf("%lld",ans);
    return 0;
}
//aabbc
//cbbaa
