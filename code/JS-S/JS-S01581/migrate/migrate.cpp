#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,t;
int n,d;
int a[N];
bool f;

int cal(int x,int y,int step,int Step){
    if(step>Step){
        return 0;
    }
    if(x==y){
        return 1;
    }
    int sum=0;
    if(a[x+1]-a[x]<=d){
        sum+=cal(x+1,y,step+1,Step);
    }
    if(x+2<=y && a[x+2]-a[x]<=d){
        sum+=cal(x+2,y,step+1,Step);
    }
    return sum;
}

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin.tie(0),cout.tie(0)->sync_with_stdio(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(c<=10){
            int ans=0;
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    int step=(a[j]-a[i]-1)/d+1;
                    if(cal(i,j,0,step)==2){
                        ans++;
                    }
                }
            }
            cout<<ans<<"\n";
        }else{
            cout<<"0\n";
        }
    }
    return 0;
}
