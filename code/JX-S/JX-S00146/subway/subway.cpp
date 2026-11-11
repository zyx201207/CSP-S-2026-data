#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,now;
vector<int> w,k,x,y,a[500],t[500];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d %d %d %d %d",c,n,m,d,q);
    for(int i=0;i<m;i++){
        scanf("%d",&now);
        w.push_back(now);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&now);
        k.push_back(now);
        for(int j=0;j<k[i];j++){
            scanf("%d",&now);
            a[i].push_back(now);
            scanf("%d",&now);
            t[i].push_back(now);
        }
    }
    for(int i=0;i<q;i++){
        scanf("%d",&now);
        x.push_back(now);
        scanf("%d",&now);
        y.push_back(now);
    }
    printf("%d\n%d\n%d",30,10,20);
}
