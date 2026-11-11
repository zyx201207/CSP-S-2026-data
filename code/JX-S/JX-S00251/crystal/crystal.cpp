#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int ans=0;
int n,m;
int a[N];
int diff[N][N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            diff[i][j]=abs(a[i]-a[j]);
        }
    }
    for(int i=1;i<=n;i++){
        int sum=0,tot=-1;
        int num[N]={0};
        for(int j=1;j<=n;j++){
            num[j]=diff[i][j];
        }
        sort(num+1,num+n+1);
        for(int j=1;j<=n;j++){
            if(sum>m) break;
            sum+=num[j];
            tot++;
        }
        ans=max(ans,tot);
    }
    printf("%d",ans);
    return 0;
}