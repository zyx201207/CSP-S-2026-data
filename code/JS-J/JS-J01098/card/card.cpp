#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,m,a[N],tot[N],b[N];
bool app[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    if(n>5000){
        int tmp=a[1],j=1;
        b[1]=a[1];
        for(int i=2;i<=n;++i){
            if(a[i]!=tmp){
                tmp=a[i];
                b[++j]=tmp;
            }
        }
        for(int i=2;i<=j;++i){
            a[i]=b[i];
        }
        n=j;
    }
    for(int i=1;i<=n;++i){
        for(int j=0;j<=n+10;++j){
            app[j]=0;
        }
        stack<int> stk;
        for(int j=i;j<=n;++j){
            if(app[a[j]]){
                while(!stk.empty()&&stk.top()!=a[j]){
                    app[stk.top()]=0;
                    stk.pop();
                }
            }else{
                stk.push(a[j]);
                app[a[j]]=1;
            }
        }
        for(int j=1;j<=m;++j){
            tot[j]+=app[j];
        }
    }
    for(int j=1;j<=m;++j){
        cout<<tot[j]<<" ";
    }
    return 0;
}
