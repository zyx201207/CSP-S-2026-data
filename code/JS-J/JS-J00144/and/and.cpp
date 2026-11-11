/*bufang erjinzhi and & is qiu how many xiangtong are there
    kaolv yong string cunchumeigeshu
    name daan is to from m string solve there zuichanggonggongzixulie
    laolv jilv meige erjinzhi wei douyou naxie shu shi 1
*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN= 2e5+5;//here
//const int MOD= ;
int n,m;
int a[MAXN];
//int T;
int f[MAXN];//f[j]=max(f[j],f[j-1]&a[i]);
vector<int> onee[32];
int ans=-1;
void solve(int a,int pos){
    int cnt=1;
    while(a){
        int x=a%2;
        if(x==1){
            onee[cnt++].push_back(pos);
        }

        a/=2;
    }
}
bool vis[MAXN];

void dfs(int cnt,int now){

    if(cnt==m){
        ans=max(ans,now);
        return ;

    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            dfs(cnt+1,now&a[i]);
            vis[i]=0;
        }
    }
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    /*cin>>T;
    while(T--){

    }*/
    f[0]=1;
    cin>>n>>m;
    int maxn=-1,summ;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
        solve(a[i],i);
    }
    summ=a[1];
    for(int i=2;i<=n;i++){
        summ=summ&a[i];
    }
    if(m==1){
        cout<<maxn;
        return 0;
    }
    if(m==2){
        int ass=-1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                ass=max(ass,a[i]&a[j]);
            }
        }
        cout<<ass;
        return 0;
    }
    if(m==n){
        cout<<summ;
        return 0;
    }
    if(maxn<4){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            vis[i]=1,vis[j]=1;
            dfs(2,a[i]&a[j]);
            memset(vis,0,sizeof(vis));
        }
    }
    cout<<ans;
    return 0;
}
