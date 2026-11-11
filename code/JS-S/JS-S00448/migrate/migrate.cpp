#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=0,maxn=2e6+5;
int read(){
    int f=1,k=0,c=getchar_unlocked();
    for(;!isdigit(c);c=getchar_unlocked()){
        if(c=='-'){
            f=-1;
        }
    }
    for(;isdigit(c);c=getchar_unlocked()){
        k=k*10+(c^48);
    }
    return f*k;
}
int n,d,x[maxn],c,_,ans1,cur;
void dfs1(int u,int v,int tmp){
    if(tmp>ans1){
        return;
    }
    if(u==v){
        if(tmp==ans1){
            cur++;
        }
        else{
            ans1=tmp;
            cur=1;
        }
        return;
    }
    for(int i=u+1;i<=v&&x[i]-x[u]<=d;i++){
        dfs1(i,v,tmp+1);
        if(cur>2){
            return;
        }
    }
}
void solve1(){
    /*0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
    ans1=INT_MAX;
    int ans=0;
    n=read();
    d=read();
    for(int i=1;i<=n;i++){
        x[i]=read();
    }
    for(int i=1;i<=n;i++){
        for(int j=i+2;j<=n;j++){
            ans1=INT_MAX;
            cur=0;
            dfs1(i,j,0);
            if(cur==2){
                ans++;
            }
        }
    }
    cout<<ans<<"\n";
}
void solveb(){
    /*
    13 1
    7 4
    1 2 3 4 5 6 7
    */
    int ans=0;
    n=read();
    d=read();
    for(int i=1;i<=n;i++){
        x[i]=read();
    }
    cout<<ans<<"\n";
}
void solvea(){
    int ans=0;
    n=read();
    d=read();
    for(int i=1;i<=n;i++){
        x[i]=read();
    }
    int gx=x[2]-x[1],tmp=d/gx*2-1;
    //cout<<n<<" "<<gx<<" "<<d<<" "<<tmp<<"\n";
    if(d/gx<2){
        cout<<"0\n";
    }
    else{
        cout<<max(0LL,n-tmp)<<"\n";
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read();
    _=read();
    while(_--){
        if(c<=2){
            solve1();
        }
        else if(c==13||c==14){
            solveb();
        }
        else if(c==11||c==12){
            solvea();
        }
    }
    return 0;
}


/*
li jie le
yi dian ye bu hao wan
fang wo hui qu wan osu
(wei she me kao shi shi jian zhe me wan,hui qu wo dou mei shi jian qu dawu meng le)
*/
