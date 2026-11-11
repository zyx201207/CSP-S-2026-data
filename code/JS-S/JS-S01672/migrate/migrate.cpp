#include<bits/stdc++.h>//17:40 skip T2,maybe 8 pts
using namespace std;
#define int long long
const int N=2e6+5;
int n,d,x[N],ans,sum,cnt;
void fly2(int from,int to,int xum){
    //cout<<"#"<<from<<"\n";
    if(xum>sum)return;
    if(from==to){
        if(sum>xum){
            cnt=1;
            sum=xum;
            //cout<<"xum:"<<xum<<"\n";
        }
        else cnt++;
        return;
    }
    for(int i=from+1;i<=to;i++){
        if(x[i]-x[from]<=d){
            fly2(i,to,xum+1);
        }
    }
    return;
}
void sol(){
   ans=0;
    cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>x[i];
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            sum=LLONG_MAX,cnt=0;
            if(x[j]-x[i]>d&&j-i==1)continue;
            fly2(i,j,0);
            //cout<<"i:"<<i<<" j:"<<j<<" k:"<<cnt<<"\n";
            if(cnt==2)ans++;
        }
    }
    cout<<ans<<"\n";
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,T;
    cin>>c>>T;
    while(T--)sol();
    return 0;
}
