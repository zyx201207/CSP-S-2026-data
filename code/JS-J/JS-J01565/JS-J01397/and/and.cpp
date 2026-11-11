#include<bits/stdc++.h>
using namespace std;
int n,m;
int dp[21][21],a[200005];
bool d[200005];
int dfs(int i,int z){
    if(i==0)
        return z;
    int ans=0;
    for(int j=1;j<=n;j++){
        if(!d[j]){
            d[j]=true;
            ans=max(ans,dfs(i-1,a[j]&z));
            d[j]=false;
        }
    }
    return ans;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    if(n<=20){
        printf("%d\n",dfs(m,(1<<20)-1));
        return 0;
    }
    if(n<=2000&&m==1){
        int ans1=0;
        for(int i=1;i<=n;i++){
            ans1=max(ans1,a[i]);
        }
        printf("%d\n",ans1);
        return 0;
    }
    if(n<=2000&&m==n){
        int ans2=0;
        for(int i=1;i<=n;i++){
            ans2=ans2&a[i];
        }
        printf("%d\n",ans2);
        return 0;
    }  
    if(n<=2000&&m==2){
        int ans3=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++)
                ans3=max(ans3,a[i]&a[j]);
        }
        printf("%d\n",ans3);
        return 0;
    }    
    sort(a+1,a+n+1);
    bool f=true,f2=true;
    for(int i=1;i<n;i++){
        if((a[i+1]+1)%(a[i]+1)!=0){
            f=false;
        }
        if(a[i]>3||a[i+1]>3)
            f2-false;
    }
    if(f){
        printf("%d\n",a[n-m+1]);
        return 0;
    }
    if(f2){
        int aa[4];
        for(int i=1;i<=n;i++){
            aa[i]++;
        }
        if(aa[3]>=m){
            printf("3\n");
            return 0;
        }
        if(aa[3]+aa[2]>=m){
            printf("2\n");
            return 0;
        }
        if(aa[2]+aa[3]+aa[1]>=m){
            printf("1\n");
            return 0;
        }
        printf("0\n");
        return 0;
    }
    printf("0\n");
    return 0;
}       