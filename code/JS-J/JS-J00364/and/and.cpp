#include <iostream>
using namespace std;
int m,n,dp;
int a[200010];
int ad(int x,int y){
    int i=1,s=0,v=0,ans=0;
    while(x!=0){
        s=x%2;v=y%10;
        if(s==v) ans+=i*s;
        x/=2;
        y/=10;
        i*=10;
    }

}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","r",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(ad(dp,a[i])>dp && m>0){
            dp=ad(dp,a[i]);
            m--;
        }
    }
    cout<<dp;
    return 0;
}
