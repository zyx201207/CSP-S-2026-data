#include<bits/stdc++.h>
#define ll long long
#define ull long long
#define ls(x) x<<1
#define rs(x) x<<1|1
#define N 200005
#define M 100000
#define inf 1000000000
#define pii pair<int,int>
#define endl "\n"
using namespace std;
struct node{
    int id,del;
    bool operator<(const node&a)const{
        return del<a.del;
    }
}e[N];
int chose[N];


int n,m,a[N],ans=0;
void dfs(int p, int res, int xxx){
    
    if(res==0&&p!=n+1){
        return ;
    }
    if(p>n+1){
        return;
    }
    if(p==n+1&&res==0){
        ans=max(ans,xxx);
        return ;
    }
    if(res){
        chose[p]=1;
        if(xxx==-1)dfs(p+1,res-1,a[p]);
        else dfs(p+1,res-1,xxx&a[p]);
    }
    chose[p]=0;
    dfs(p+1,res,xxx);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n<=20){
        dfs(1,m,-1);
        cout<<ans<<endl;
        return 0;
    }
    if(m==1){
        int mx=-1e9;
        for(int i=1;i<=n;i++){
            mx=max(a[i],mx);
        }
        cout<<mx<<endl;
        return 0;
    }
    else if(m==2){
        int mx=-1e9;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[i]==a[j])continue;
                mx=max(a[i]&a[j],mx);
            }
        }
        cout<<mx<<endl;
    }
    else if(m==n){
        int ans=a[1];
        for(int i=1;i<=n;i++){
            ans&=a[i];
        }
        cout<<ans<<endl;
        return 0;
    }
    int A=1,B=1;int f=0;
    for(int i=1;i<=n;i++){
        if(a[i]!=i-1)B=0;
        for(int j=0;j<30;j++){
            if(a[i]&(1<<j)==0){
                A=0;
                goto E;
            }
        }
    }
    for(int j=0;j<30;j++){
        if(n^(1<<j)==0){
            f=1;
        }
    }
    B&=f;
    E:;
    if(A){
        sort(a+1,a+n+1);
        cout<<a[n-m+1]<<endl;
    }
    return 0;
}