#include<bits/stdc++.h>
using namespace std;
const int mxN=5e5+5;
int n,mx;
long long int a[mxN],b[mxN][2],m,p;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    stable_sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        if(a[i]!=b[p][0]) b[++p][0]=a[i];
        b[p][1]++;
    }
    for(int i=1;i<=p;i++){
        int ans=0,sum=b[i][1];
        for(int j=i-1;j>=1;j--){
            if((ans+(b[i][0]-b[j][0])*b[j][1])<=m){
                ans+=((b[i][0]-b[j][0])*b[j][1]);
                sum+=b[j][1];
            }else{
                sum+=((m-ans)/(b[i][0]-b[j][0]));
                break;
            }
        }
        mx=max(mx,sum);
    }
    printf("%lld",mx);
    return 0;
}
