#include<bits/stdc++.h>
using namespace std;
int c,t;
int hs()
{
    int a[2000001];
    int n;int d;
    scanf("%d %d",&n,&d);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    //if(c==11||c==12) return max(0,n-3);
    int jiangeshu=n-1;
    int cha=a[2]-a[1];
    d=d/cha;
    return max(0,jiangeshu-2*d+2);

}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d %d",&c,&t);
    //c=11;
    for(int i=1;i<=t;i++)
        printf("%d\n",hs());


    return 0;
}//60
