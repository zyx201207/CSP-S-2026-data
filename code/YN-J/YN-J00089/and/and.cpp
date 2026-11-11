#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
ll flag,n,m,a[N],ans,ans1,ans2,ans3,ans4,vis[N];
bool check(ll x){
    for(ll i=0;i<=20;i++){
        if(x==pow(2,i)-1)return 1;
    }
    return 0;
}
void dfs(ll x,ll num){
    if(x==m){
//        cout<<"m:"<<m<<'\n';
//        cout<<"x:"<<x<<'\n';
//        cout<<"num:"<<num<<'\n';
        ans=max(ans,num);
        return;
    }
    for(int i=x+1;i<=n;i++){
//        cout<<"x:"<<x<<" i:"<<i<<'\n';
        if(x==0){
            vis[a[i]]=1;
            dfs(x+1,a[i]);
            vis[a[i]]=0;
        }
        else{
            if(vis[a[i]])continue;
            vis[a[i]]=1;
            dfs(x+1,(num & a[i]));
            vis[a[i]]=0;
        }
    }
}
int cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
//    cout<<n<<' '<<m<<'\n';
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if((!flag) && (!check(a[i])))flag=1;
        ans1=max(ans1,a[i]);
        if(i==1)ans2=a[i];
        else ans2=(ans2 & a[i]);
    }
    if(n<=20){
        dfs(0,0);
        cout<<ans<<'\n';
    }
    else if(m==1)cout<<ans1<<'\n';
    else if(m==n)cout<<ans2<<'\n';
    else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans3=max(ans3,(a[i] & a[j]));
            }
        }
        cout<<ans3<<'\n';
    }
    else if(!flag){
        sort(a+1,a+n+1,cmp);
        cout<<a[m]<<'\n';
    }
    else{
        sort(a+1,a+n+1,cmp);
        ans4=a[1];
        for(int i=2;i<=m;i++)ans4=(ans4 & a[i]);
        cout<<ans4<<'\n';
    }
    return 0;
}
