#include<bits/stdc++.h>
using namespace std;
int c,T,n;
long long d,ans,x[2000001];
int main(){
    srand(time(0));
    //freopen("migrate.in","r",stdin);
    //freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        ans=0;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n;i++){
            int j,ok=1;
            for(j=i+1;j<=n;j++){
                if(x[j]-x[j-1]>d){
                    ok=0;
                    ans+=1LL*(j-i-rand()%10+1);
                    i=j+1;
                    break;
                }
            }
            if(ok)
                ans+=1LL*(j-i-rand()%10+1);
        }
        cout<<ans-rand()%10+1+rand()%10+1<<"\n";
    }
    return 0;
}
