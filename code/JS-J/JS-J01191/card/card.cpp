#include<bits/stdc++.h>
using namespace std;
stack<int> s;
bool f[300005];
int t[300005];
int a[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int j=1;j<=n;j++){
        for(int i=j;i<=n;i++){
            if(f[a[i]]==true){
                do{
                    f[s.top()]=false;
                    s.pop();
                }while(s.top()!=a[i]);
            }
            s.push(a[i]);
            f[a[i]]=true;
        }
        for(int i=1;i<=m;i++){
            t[i]+=f[i];
        }
        memset(f,0,sizeof f);
    }
    for(int i=1;i<=m;i++){
        cout<<t[i]<<' ';
    }
    return 0;
}
