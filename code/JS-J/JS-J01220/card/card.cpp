#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
stack<int> stk;
int n,m;
int a[N],u[N],ans[N];
void prep();
void init();
void dr();
void work();
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    int T=1;
//    cin>>T;
    prep();
    while(T--){
        init();
        dr();
        work();
    }
    return 0;
}
void prep(){
}
void init(){
}
void dr(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
}
void work(){
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) u[j]=0;
        for(int j=i;j<=n;j++){
            if(u[a[j]]==1){
                while(!stk.empty()&&stk.top()!=a[j]) u[stk.top()]=0,stk.pop();
                stk.pop();
                stk.push(a[j]);
            }
            else stk.push(a[j]),u[a[j]]=1;
            //(cnt==n-6) return;
            //cnt++;
        }
        while(!stk.empty()) ans[stk.top()]++,stk.pop();
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
}
