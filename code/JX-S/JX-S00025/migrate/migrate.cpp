#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;
int x[maxn];
int main(){
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
int c,T;
cin>>c>>T;
while(T--){
        memset(x,0,sizeof x);
    int n,d,ans=0,flag=0;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>x[i];
        if(x[i]>d&&flag==0){
            ans=i-1;
            flag=1;
        }
    }
cout<<ans<<'\n';
}
return 0;
}
