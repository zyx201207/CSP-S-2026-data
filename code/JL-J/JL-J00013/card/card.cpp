#include<bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 10;
int n,m,a[N],temp[N],k=0;
int b[N][3];
/*
4 3
1 2 1 3
*/
bool check(int x)
{
    for(int i=1;i<=k;i++){
        if(x == temp[i]) return true;
    }
    return false;
}
void huishou(int n)
{
    int p;
    for(int i=1;i<=k;i++){
        if(temp[i] == n){
            p = i;
            break;
        }
    }
    int sum = 0;
    for(int i=p;i<=k;i++){
        temp[i] = 0;
        sum++;
    }
    k -= sum - 1;
    temp[p] = n;
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int u = 1;
    for(int i=1;i<=m;i++) b[i][1] = i;
    for(int u=1;u<=n;u++){
        memset(temp,0,sizeof(temp));
        k = 0;
        for(int i=u;i<=n;u++){
            if(!check(a[i])){
                k++;
                temp[k] = a[i];
            }else{
                huishou(a[i]);
            }
            for(int j=1;j<=k;j++){
                for(int l=1;l<=m;l++){
                    if(temp[j] == b[l][1]) b[i][2]++;
                }
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i][2]<<" ";
    }
    return 0;
}
