#include<bits/stdc++.h>
using namespace std;
int n;
long long d,a[2000010];
int e=0,f=0;
void dfs(int l,int r,int x,int y,int z){
    if(e>2) return ;
    if(a[r]-a[x]>(z-y)*d) return ;
    if(y>z) return ;
    if(x==r&&y==z){
        e++;
        return ;
    }
    int f=r;
    while(a[f]-a[x]>d) f--;
    for(int i=f,j=1;i>=x+1;i--,j++){
        if(j>=3) break;
        dfs(l,r,i,y+1,z);
    }
}
bool pd(int l,int r){
    for(int i=l;i<r;i++){
        if(a[i+1]-a[i]>d) return 0;
    }
    int lo=0;
    for(int i=l,k=i;i<=r;){
        k=i;
        if(i==r) break;
        int j=i+1;
        while(a[j]-a[i]<=d&&j<=r) j++;
        j-=1;
        i=j;
        lo++;
    }
    e=0;
    dfs(l,r,l,0,lo);
    if(e!=2) return 0;
    return 1;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int t,c;
    cin>>c>>t;
    while(t--){
        scanf("%d %lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        int r=0;
        for(int i=1;i<=n;i++){
            for(int j=i+3;j<=n;j++){
                if(pd(i,j)==1){
                    r++;
                    while(j<n&&a[j+1]-a[j-1]>d&&a[j+1]-a[j]<=d){
                        j++;
                        r++;
                    }
                }
            }
        }
        printf("%d\n",r);
    }
    return 0;
}
