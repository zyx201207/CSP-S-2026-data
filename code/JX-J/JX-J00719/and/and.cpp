#include<bits/stdc++.h>
using namespace std;
long long ans,f[2000005],o[100005],sum;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(m==1){
        for(int i=1;i<=n;i++){
            int a;
            cin>>a;
            if(a>ans)ans=a;
        }
        cout<<ans;
        return 0;
    }else{
     for(int i=1;i<=n;i++){
            cin>>f[i];
     }
     sort(f+1,f+1+n);
        sum+=f[n];
        m--;
     while(m--){
        sum=(sum&f[n-1+m]);
     }
     cout<<sum;
    }
    return 0;
}
