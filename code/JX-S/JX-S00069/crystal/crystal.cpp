#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long a[n+5],cost[n+5];
    cost[0]=0;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        if(cost[i-1]<=m){
            cost[i]=cost[i-1]+(max(a[i],a[i-1])-min(a[i],a[i-1]))*(i-1);
        }
        else cost[i]=100000000000000000000;
    }
    long long s[n+5][m+5];
    for(long long i=1;i<=n;i++){
        s[i][0]=1;
        for(long long j=1;j<=m;j++){
            s[0][j]=0;
            if(j>=cost[i]){
                s[i][j]=max(s[i-1][j],i);
            }
            else s[i][j]=s[i-1][j];
        }
    }
    cout<<s[n][m];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
