#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;

const int N=2e5+5;
const int L=30;

int a[N];

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int res=0;
    for(int l=L-1;l>=0;l--){
        int c=0;
        for(int i=1;i<=n;i++) if((a[i]&res)==res && a[i]&(1<<l)) c++;
        if(c>=m) res|=(1<<l);
    }
    printf("%d\n",res);
    return 0;
}
