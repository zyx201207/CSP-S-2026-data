#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200050;
int n,m,a[N];
ll sum;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int t=n;
    for(int i=30;i>=0;i--){
        int ans=0;
        for(int j=1;j<=t;j++){
            if(a[j]&(1<<i)) ans++;
        }
        if(ans>=m){
            int tot=0;
            for(int j=1;j<=t;j++){
                if(a[j]&(1<<i))
                    a[++tot]=a[j];
            }
            sum+=(1<<i);t=tot;
        }
    }
    printf("%lld",sum);
    return 0;
}

