#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int maxn=2e6+7;
constexpr int inf=2e18+7;
int c,t,n,d;
int X[maxn];
int ans;
void solve(){
    for(int i=1;i<=n;i++){
        int id1=upper_bound(X+i,X+n+1,X[i]+d)-X;
        if(id1>n)continue;
        id1--;
        
    }
}
void clear(){
    ans=0;
}
namespace sub1{
    int ans1=0;
    int D[5005],T[5005];
    void clear1(){
        ans1=0;
    }
    void solve(){
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++)cin>>X[i];
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++)D[j]=inf;
                for(int j=1;j<=n;j++)T[i]=0;
                D[i]=0;T[i]=1;
                for(int j=i+1;j<=n;j++){
                    for(int k=j-1;k>=i;k--){
                        if(X[j]-X[k]<=d){
                            if(D[j]>D[k]+1)D[j]=D[k]+1,T[j]=T[k];
                            else if(D[j]==D[k]+1)T[j]+=T[k];
                        }else{
                            break;
                        }
                    }
                }
                for(int j=1;j<=n;j++)if(T[j]==2)ans1++;
            }
            cout<<ans1<<'\n';
            clear1();
        }
        exit(0);
    }
}
namespace sub2{
    int ans2=0;
    int T[5005];
    queue<int>pre_max_[2];//save 3*2 
    int tt[2];
    bool ps;//ps is max1 ,!ps is max2
    void clear2(){
        ans2=0;
    }
    void nxt(){
        while(!pre_max_[!ps].empty())pre_max_[!ps].pop();tt[!ps]=0;
        ps=!ps;
    }
    void solve(){
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++)cin>>X[i];
            for(int i=1;i<=n;i++){
                nxt();nxt();
                for(int j=1;j<=n;j++)T[i]=0;
                T[i]=1;
                pre_max_[ps].push(i);tt[ps]=1;
                for(int j=i+1;j<=n;j++){
                    while(!pre_max_[!ps].empty()&&X[j]-X[pre_max_[!ps].front()]>d)tt[!ps]-=T[pre_max_[!ps].front()],pre_max_[!ps].pop();
                    if(!pre_max_[!ps].empty()){
                        T[j]=tt[!ps];
                        pre_max_[ps].push(j);
                        if(pre_max_[ps].size()>3)pre_max_[ps].pop();
                        tt[ps]+=T[j];
                    }else{
                        nxt();
                        while(!pre_max_[!ps].empty()&&X[j]-X[pre_max_[!ps].front()]>d)tt[!ps]-=T[pre_max_[!ps].front()],pre_max_[!ps].pop();
                        if(pre_max_[!ps].empty())break;
                        T[j]=tt[!ps];
                        pre_max_[ps].push(j);
                        if(pre_max_[ps].size()>3)pre_max_[ps].pop();
                        tt[ps]+=T[j];
                    }
                }
                for(int j=i+1;j<=n;j++)if(T[j]==2)ans2++;
            }
            cout<<ans2<<'\n';
            clear2();
        }
        exit(0);
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>c>>t;
    if(c>=1&&c<=6){
        sub1::solve();
    }
    if(c>=7&&c<=10){
        sub2::solve();
    }
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>X[i];
        solve();
        cout<<ans<<'\n';
        clear();
    }
}