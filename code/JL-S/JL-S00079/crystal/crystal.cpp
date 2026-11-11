#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,ans;
ll a[500001],s[500001],m;
ll need(int id,int cnt){
    return a[id]*cnt-(s[id-1]-s[id-cnt-1]);
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=a[i]+s[i-1];
    }
    for(int i=n;i;i--){
        int L=0,R=i;
        while(L+1<R){
            int M=(L+R)/2;
//          printf("%d %d %d %d %lld\n",i,L,R,M,need(i,M));
            if(need(i,M)<=m){
                L=M;
            }else{
                R=M;
            }
        }
        ans=max(ans,L);
    }
    cout<<ans+1;
}
