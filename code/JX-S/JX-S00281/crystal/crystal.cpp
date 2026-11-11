#include<bits/stdc++.h>
using namespace std;
long long a[100000005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    long long sum=0,ans=0,cnt=0;
    for(int i=0;i<=n;i++){
        cin>>a[i];
    }
    while(sum<=m){
        for(int i=0;i<=n;i++){
            cnt+=a[i++];
            cnt=cnt/n;
            int c=max(a[i],cnt);
            if(c<cnt){
                sum+=cnt-c;
                int c=a[i++];
                ans++;
            }
        }
    }
    for(int i=0;i<=n;i++){
        if(a[i+1]-a[i]==a[i]-a[i-1]){
            int b=0;
        }
    }
    cout<<ans+1;
    return 0;
}
