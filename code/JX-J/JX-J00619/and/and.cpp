#include<iostream>
using namespace std;
int a[200005],cnt;
int n,m;
int maxn=-1;
void f(int id,int x,int sum){
    if(id==m+1){
        maxn=max(maxn,sum);
        return;
    }
    for(int i=x+1;i<=cnt;i++){
        f(id+1,i,sum&a[i]);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        if(x>=0){
            a[++cnt]=x;
        }
    }
    for(int i=1;i<=cnt;i++){
        f(2,i,a[i]);
    }
    cout<<maxn;
    return 0;
}

