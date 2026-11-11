#include<iostream>
#include<sys/procfs.h>
#include<string>
#include<algorithm>
using namespace std;
int n,m;
long long a[100005];
long long ans;
long long jl[2005][2005];
long long dp[100005];

long long  find_(int x,int i,long long num){
    int arr[100005];
    if(x==m+1)return num;
    for(int j=i+1;j<=n;j++){
        num=(num&a[j]);
        arr[j]=find_(x+1,j,num);
    }int maxx=0;
    for(int j=i+1;j<=n;j++){
        maxx=max(arr[j],maxx);
    }
    return maxx;


}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==m){
        ans=a[1];
        for(int i=2;i<=n;i++){
            ans=ans&a[i];
        }cout<<ans;return 0;
    }if(m==1){
        long long maxx=0;
        for(int i=1;i<=n;i++){
            maxx=max(maxx,a[i]);
        }cout<<maxx;return 0;
    }if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(jl[i][j]!=0)continue;
                jl[i][j]=jl[j][i]=(a[i]&a[j]);
            }
        }for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                ans=max(ans,jl[i][j]);
            }
        }cout<<ans;return 0;
    }for(int i=1;i<=n;i++){
        dp[i]=find_(1,i,a[i]);
    }for(int i=1;i<=n;i++){
        ans=max(ans,dp[i]);
    }cout<<ans;


    return 0;
}

