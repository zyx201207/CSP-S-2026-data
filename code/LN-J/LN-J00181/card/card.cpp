#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005]={0},f[1000005]={0},card[1000005]={0},ans[1000005]={0};
long long f2[1000005]={0},ll;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=m;j++){
            f[j]=0;
            card[j]=0;
            f2[j]=0;
        }
        for(long long j=i;j<=n;j++){
            card[j-i+1]=a[j];
            f[a[j]]++;
            if(f[a[j]]==2){
                for(long long k=f2[f[a[j]]]-1;k<j-i+1;k++){
                    f[card[k]]--;
                    f2[card[k]]=0;
                    card[k]=-1;
                    f[a[j]]=1;
                }
            }
            f2[a[j]]=j-i+1;
        }
        for(long long j=1;j<=n-i+1;j++){
            if(card[j]>=0){
                ans[card[j]]++;
            }
        }
    }
    for(long long j=1;j<=m;j++){
        cout<<ans[j]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
