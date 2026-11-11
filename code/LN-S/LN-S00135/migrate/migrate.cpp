#include<iostream>
#include<vector>
#include<string>
using namespace std;
const int MAXN=2000001;
long long x[2000001];
void solve(){
    int n=0;
    long long d=0;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    //vector<vector<int> > v(n+1,vector<int>(n+1));
    int shortest=9999999;
    int cnt=0;
    long long ans=0;
    auto dfs=[&](auto self,int on,int y,int dep)->void{
        if(on==y){
            if(dep<shortest){
                shortest=dep;
                cnt=1;
            }else if(dep==shortest){
                cnt++;
            }
            return;
        }
        for(int i=on+1;i<=y;i++){
            if(x[i]-x[on]<=d){
                self(self,i,y,dep+1);
            }
        }
    };
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            shortest=9999999;
            cnt=0;
            dfs(dfs,i,j,0);
            if(cnt==2){
                ans++;
            }
        }
    }
    cout<<ans<<"\n";
    return;
}
void solveA(){
    int n=0;
    long long d=0;
    cin>>n>>d;
    //cout<<"n="<<n<<endl;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    //cout<<"-\n";
    long long p=x[2]-x[1];
    long long jump=d/p;
    //cout<<"jump="<<jump<<endl;
    if(jump<=0) return void(cout<<"0\n");
    //vector<vector<int> > v(n+1,vector<int>(n+1));
    long long ans=(n-1ll)*n/2;
    for(int i=1;i<=n;i++){
        ans-=(n-i)/jump;
    }
    cout<<ans<<"\n";
    return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int c=0,t=0;
    cin>>c>>t;
    //cout<<c<<endl;
    for(int i=1;i<=t;i++){
        if(c!=11 && c!=12)solve();
        else solveA();
    }
    return 0;
}
