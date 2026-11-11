#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
#define int long long
int c,t,n,d,mi=0x3f3f3f,nums,cnt;
int a[N];
vector<int> v[N];
void dfs(int x,int y,int sum){
    if(x==y-1){
        if(sum<mi) mi=sum,cnt=1;
        if(sum==mi) cnt++;
        return;
    }
    for(auto b : v[x]){
        dfs(b,y,sum+1);
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        memset(v,0,sizeof(v));
        cin>>n>>d;
        nums=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[j]-a[i]<=d) v[a[i]].push_back(a[j]);
                else break;
            }
        }
        for(int i=1;i<=n-3;i++){
            for(int j=i+3;j<=n;j++){
                mi=0x3f3f3f;
                cnt=0;
                dfs(i,j,0);
                if(cnt==2) nums++;
            }
        }
        cout<<nums<<endl;
    }
    return 0;
}
