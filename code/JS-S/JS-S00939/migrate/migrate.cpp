#include<bits/stdc++.h>
using namespace std;
const int maxn=2000010;
int c,t;
int x[maxn];
int solve(){
    memset(x,0,sizeof(x));
    int n,d;
    scanf("%d%d",&n,&d);
    int f=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&x[i]);
    }
    for(int i=2;i<n;i++){
        if(x[i]-x[i-1]!=x[i+1]-x[i]) f=1;
    }
    if(f==0){
        int l=x[2]-x[1];
        int s=d/l;
        int a=2*s-1;
        int ans=n-a;
        return ans;
    }

    return 0;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        printf("%d\n",solve());
    }
    return 0;
}
