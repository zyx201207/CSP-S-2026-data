//记得取消注释
//long long
#include <iostream>
#include <queue>
#include <algorithm>

#define ll long long
using namespace std;

int n;
ll m,a;
queue<ll> q;
ll total;
int maxn,nown;
ll last;
ll delta,delta1;
bool flag=true;

int main(){
    freopen("test.out","r",stdin);
    //freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a);
        if(i>=2){
           delta1=a-last;
           if(i>=3&&delta!=delta1){
                flag=false;
           }
           delta=delta1;
        }
        if(i==5&&flag==true){
            break;
        }
        q.push(a);
        total=total+a*(maxn+1);
        while(total>m){
            total=total-(a-q.front());
            q.pop();
            nown--;
        }
        nown++;
        maxn=max(nown,maxn);
        last=a;
    }
    if(flag==true){
        int i=0;
        while(++i){
            m-=(i*delta);
            if(m<0){
                printf("%d",i);
                return 0;
            }
        }
    }
    printf("%d",maxn+1);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
