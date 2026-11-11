#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int c,t,land[2000005],rujing=0,ru[114514]={0};
inline void dfs(int u,int v,int d,int fly=0){
    if(u>v) return;
    if(u==v) ru[fly]++;
    for(int i=1;i<=d;i++) dfs(u+i,v,d,fly+1);
    return;
}
int solve(int n,int d,int* land){
    int sum=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++,rujing=0){
            dfs(i,j,d);
            sort(ru,ru+114514);
            if(ru[0]==2) sum++;
            memset(ru,0,sizeof(ru));
        }
    }
    return sum;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=0;i<t;i++){
        int n,d;
        cin>>n>>d;
        for(int i=0;i<n;i++) cin>>land[i];
        cout<<solve(n,d,land)<<endl;
        memset(land,0,sizeof(land));
    }

    return 0;
}