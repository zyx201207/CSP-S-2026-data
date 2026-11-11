// this is NO.1 : crystal  
#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long n,m,ans=-1; 
void fd(int sheng){
    if(sheng<=0){
        long long b[400]={0};
        for(int i=0;i<n;i++){
            b[a[i]+20]++;
        }
        for(int i=0;i<400;i++){
            ans=max(ans,b[i]);
        }
        return;
    }

    for(int i=0;i<n;i++){
        a[i]++;
        fd(sheng-1);
        a[i]--;
    }
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    fd(m);
    printf("%lld",ans);
    return 0;
}