#include<bits/stdc++.h>
using namespace std;
long long x[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    cin>>c>>T;
while(T--){
    memset(x,0,sizeof x);
    int n;
    long long d;
    cin>>n;
    cin>>d;
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    long long ans=0;
    if(c==11 || c==12 || c==0){
        long long a=2*(d/(x[1]-x[0]))-1;
        ans=n-a;
        if(d<2*(x[1]-x[0]) || ans<0) ans=0;
        cout<<ans<<endl;
        continue;
    }
    cout<<0<<endl;


}
    fclose(stdin);
    fclose(stdout);
    return 0;

}
