#include<bits/stdc++.h>
using namespace std;
long long n,m,energy[500010],checkB=0;
bool flagA = true,flagB = true;
bool cmp(long long a,long long b){return a<b;}
int main(){
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>energy[i];
        if(energy[i]!=i)flagA = false;
        if(i>1){
            if(checkB!=0)if(checkB != energy[i]-energy[i-1])flagB = false;
            if(checkB == 0)checkB = energy[i] - energy[i-1];
        }
    }
    if(flagA){
        if(n*(n+1)/2<=m)cout<<n;
        else cout<<int((-1+int(sqrt(1+8*m)))/2);
        return 0;
    }
    if(flagB){
        if(checkB*n*(n+1)/2<=m)cout<<n;
        else cout<<int((-1+int(sqrt(1+8*int(m/checkB))))/2);
        return 0;
    }
    sort(energy+1,energy+n+1,cmp);
    long long ans=0;
    for(long long i=2;i<=n;i++){
        long long total=0;
        for(long long j = i-1;j>=1;j--){
            total+=energy[i]-energy[j];
            if(total<=m)ans = max(ans,i-j+1);
        }
    }
    cout<<ans;
    return 0;
}
