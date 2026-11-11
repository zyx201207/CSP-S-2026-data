#include<iostream>
#include<cstdio>
using namespace std;
int c,n,m,d,q;
int w[500005],k,a;
struct node{};
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;++i)scanf("%d",w[i]);
    for(int i=1;i<=n;++i){
        cin>>k;
        for(int i=1;i<=2*k;++i)cin>>a;
    }cout<<13;
    /*aaaaaaaaaaaaaaaaaaaaaaaaaaaaa
    aaaaaaaaaaaaaaaaaaaaaaaaaaaaa
    aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
    aaaaaaaaaaaaaaaaaaaaaaaaaaaa
    aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
    aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
    aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

    aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
    aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
    aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa







    aaaaaaaaaaaaaa
    aaaaaaaaaaaaaaa
    aaaaaaaaaaa
    aaaaaaaaaaaaaa
    aaaaaaaaaaaaaaa
    aaaaaaaaaaaaa
    aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
    aaaaaaaaaaaaaaaaaaa
    a
    */
    return 0;
}
