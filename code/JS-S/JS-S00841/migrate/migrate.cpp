#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
typedef long long LL;
int c,T;
LL dis;
LL x[N];
int n;
int g[N];//right
int f[N];//left
void work1()
{
    LL tmp = x[2]-x[1];
    if(tmp > dis) 
    {
        printf("0\n");
        return ;
    }
    LL k = dis/tmp;
    k++;
    if(k >= n ) 
    {
        printf("0\n");
        return ;
    }
    if(k <= 1) 
    {
        printf("0\n");
        return ;
    }
    int h1 =  n-k;
    int h2 = n-2*k+2;
    if(h2 <= 1) h2 = 1;
    printf("%lld\n",1ll*(h1 + h2)*(h1-h2+1)/2);
}
void work2()
{
    
}
void work3()
{

}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&T);
    while(T--)
    {
        scanf("%d%lld",&n,&dis);
    for(int i = 1;i<= n;i++) scanf("%lld",&x[i]);
    if(x[n]-x[1] <= dis) 
    {
        cout<<0;
        continue;
    }
    if(c >= 11 && c<= 12) work1();
    if(c >= 13 && c <= 14) work2();
    if(n<= 6) work3();
    }
    return 0;
}