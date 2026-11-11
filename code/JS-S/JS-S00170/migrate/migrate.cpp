#include<bits/stdc++.h>
using namespace std;
ifstream fin("migrate1.in");
ofstream fout("migrate.out");
long long c,t;
long long n,k;
long long a[2000010];
long long f[5010][5010]={2147483647};
long long fla[5010][5010];
int main(){
    fin>>c>>t;
    if(c>=11){
        while(t--){
    fin>>n>>k;
    for(int i=0;i<n;i++){
        fin>>a[i];
    }
    int ds=a[n-1]-a[n-2];
    long long ans=0;
    for(int i=3;i<n;i++){
        if((i-1)*ds>=k and k>ds*(i-2)){
            ans+=n-i;
        }
    }
    fout<<ans<<"\n";
        }
    }
    else{
         while(t--){
            fin>>n>>k;
            for(int i=0;i<n;i++){
                fin>>a[i];
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<i;j++){
                    if(a[i]-a[j]<=k){
                        f[i][j]=1;
                    }
                    else{
                        f[i][j]=2147483648;
                    }
                }
            }
            for(int i=0;i<n;i++){
                for(int k=0;k<n;k++){
                    for(int j=0;j<i;j++){
                        f[i][j]=min(f[i][j],f[max(i,k)][min(i,k)]+f[max(j,k)][min(j,k)]);
                    }
                }
            }
            for(int k=0;k<n;k++){
                for(int i=0;i<n;i++){
                    for(int j=0;j<i;j++){
                            if(f[i][j]==f[max(i,k)][min(i,k)]+f[max(j,k)][min(j,k)] and i!=k and j!=k){
                                fla[i][j]++;
                            }
                    }
                }
            }
            long long ans=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<i;j++){
                    if(fla[i][j]==2){
                            ans++;
                    }
                }
            }
            fout<<ans<<"\n";
        }
    }
}
