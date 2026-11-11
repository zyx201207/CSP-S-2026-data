#include<bits/stdc++.h>
using namespace std;
int n;
struct rp{
    int m;
    char c;
}a[200010];
long long an;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %c",&a[i].m,&a[i].c);
    }
    int i=1,j=n;
    while(i<j){
        int mi=min(a[i].m,a[j].m);
        if(a[i].c!=a[j].c) an+=mi;
        a[i].m-=mi,a[j].m-=mi;
        if(a[i].m==0) i++;
        if(a[j].m==0) j--;
    }
    printf("%lld",an);
    return 0;
}
