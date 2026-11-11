#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
stack<int> s;
int f[300005];
int y[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(f[a[j]]==1){
                while(s.top()!=a[j]){
                    s.pop();
                }
                s.pop();
            }
            s.push(a[j]);
        }
        while(!s.empty()){
            y[s.top()]++;
            s.pop();
        }
        for(int j=1;j<=m;j++){
            f[j]=0;
        }
    }
    for(int i=1;i<=m;i++){
        printf("%d ",y[i]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
