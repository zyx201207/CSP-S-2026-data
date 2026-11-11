#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+3;
int c,t,num=LLONG_MAX;
int x[N],f[N][N];
void fff(int x,int y,int sum,int d){
    if(x>y)return;
    sum++;
    if(x==y){
        if(num==sum)ans++;
        num=min(num,sum);
        return;
    }
    for(int i=d;i>=1;i--){
        fff(x+i,y,sum,d);
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[N];
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(i!=j)fff(i,j,0,d);
        cout<<ans<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
