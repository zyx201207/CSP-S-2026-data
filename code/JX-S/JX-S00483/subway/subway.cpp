#include<bits/stdc++.h>
using namespace std;
int a[500005];
struct s{
    int t[505];
    int n[505];
    int c;
}b[505];
int t=0,maxn=0;
void f1(int e,int g,int i){
    t+=b[e].t[i]+a[i];
    if(e==g){
        maxn=max(t,maxn);
    }
    for(int j=1;j<=b[j].c;j++){
        f1(b[e].n[j],g,j);
    }
    t-=b[e].t[i];
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","s",stdout);
    int c,n,m,d,q;
    scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        int e;
        int a1,a2;
        cin>>e;
        for(int j=1;j<=e;j++){
            if(j==e){
                cin>>b[a1].t[++b[a1].c];
                break;
            }
            cin>>a1;
            a2=a1;
            cin>>b[a1].t[++b[a1].c]>>a1;
            b[a2].n[b[a2].c]=a1;
        }
    }
    while(q--){
        int e,f;
        cin>>e>>f;
        maxn=0;
        f1(e,f,1);
        cout<<maxn<<endl;
    }
    return 0;
}
