#include<bits/stdc++.h>
using namespace std;
int n,m;
bool jis[300005];
int jis2[300005];
int shu[500005];
stack<int> stk;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&shu[i]);
    }
    for(int j=1;j<=n;j++){
        for(int i=j;i<=n;i++){
            int a=shu[i];
            if(jis[a]==0){
                jis[a]=1;
                stk.push(a);
            }
            else{
                while(stk.top()!=a){
                    jis[stk.top()]=0;
                    stk.pop();
                }
            }
        }
        for(int i=1;i<=m;i++){
            jis2[i]+=jis[i];
        }
        while(stk.empty()!=1){
            jis[stk.top()]=0;
            stk.pop();
        }
    }
    for(int i=1;i<=m;i++){
        printf("%d ",jis2[i]);
    }
    return 0;
}

