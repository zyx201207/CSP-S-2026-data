#include<bits/stdc++.h>
using namespace std;
long long a[200000005];
long long cnt=1;
long long L;
int n;
char c[200000005];
char dealwith[300000005];
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    if(n==1){
        cout<<0;
        return 0;
    }
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        cin>>c[i];
        L+=a[i];
        for(long long j=cnt;j<=cnt+a[i]-1;j++){
            dealwith[j]=c[i];
        }
        cnt+=a[i];
    }
    for(long long i=1;i<=L/2;i++){
        if(dealwith[i]!=dealwith[L+1-i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
