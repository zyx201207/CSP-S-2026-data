#include<bits/stdc++.h>
using namespace std;
long long ans,a[250000];
int n,m,num[250000],f[250000][32],len;
int qw(int m){
    long long n=1;
    for(int i=1;i<=m;i++){
        n*=2;
    }
    return n;
}
void rtg(long long n,int i){
    int j=1;
    while(n){
        if(n%2==1){
            f[i][j]=1;
            j++;
        }
        else{
            f[i][j]=0;
            j++;
        }
        n/=2;
    }
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        rtg(a[i],i);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=30;j++){
            num[j]+=f[i][j];
        }
        if(num[i]>=1) len=i;
    }
    for(int i=len;i>=1;i--){
        if(num[i]>=m){
            ans+=qw(i-1);
            for(int j=1;j<=n;j++){
                if(f[j][i]==0){
                    for(int k=1;k<=len;k++){
                        if(f[j][k]==1){
                            f[j][k]=0;
                            num[k]--;
                        }
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
