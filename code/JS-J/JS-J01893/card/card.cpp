#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 10;
int n,m;
int a[MAXN];
int ans[MAXN];
bool inq[MAXN];
stack<int> q;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        memset(inq,false,sizeof(inq));
        for(int j=i;j<=n;j++){
            int k = a[j];
            if(inq[k]){
                while(1){
                    int x = q.top();
                    inq[x] = false;
                    q.pop();
                    if(x==k) break;
                }
                q.push(k);
                inq[k] = true;             
            }else{
                q.push(k);
                inq[k] = true;
            }
        }
        while(!q.empty()){
            int x = q.top();
            q.pop();
            ans[x]++;
        }
    }
    for(int i=1;i<=m;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}
