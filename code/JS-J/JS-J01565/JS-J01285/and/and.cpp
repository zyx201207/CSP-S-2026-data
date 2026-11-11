#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],mx=-1;
int dfs(int x,int y,int ans){
    if(x>n||y>m){
        return 0;
    }
    return max(dfs(x+1,y,ans),dfs(x+1,y+1,ans&a[x]));
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    if(m==1){
        cout<<mx;
        return 0;
    }
    cout<<dfs(1,0,(1<<30)-1);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//sto CCF orz ccw.site chat.deepseek.com
//ygg luogu:yjh_114514 ACGO:2433437 bilibili:xiao yan bu yan ya
//X X XXX  X X XXX
//ciallo~
//phigros MC BA
//fuck CCF
//wo chovy zen me mei you zhong wen shu ru fa,fuck CCF
