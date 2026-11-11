#include<bits/stdc++.h>
using namespace std;
struct sub{
    int k;
    map<int,long long> a;
    map<int,long long> t;
};
struct sq{
    map<int,long long> s;
};
int c,n,m,d,q;
long long w[500001];
sub p[500001];
sq zz[500001]={};
int main(){
    freopen("subway4.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d ",&c);
    scanf("%d ",&n);
    scanf("%d ",&m);
    scanf("%d ",&d);
    scanf("%d ",&q);
    for(int i=1;i<=m;i++){
        scanf("%ld",&w[i]);
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            if(i!=j){
                zz[i].s[j]=0xfffffff;
                zz[j].s[i]=0xfffffff;
            }
        }
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&p[i].k);
        for(int j=1;j<=p[i].k;j++){
            scanf("%ld ",&p[i].a[j]);
            scanf("%ld ",&p[i].t[j]);
        }
        for(int j=1;j<=p[i].k;j++){
            for(int l=1;l<=p[i].k;l++){
                if(l!=j){
                    zz[p[i].a[j]].s[p[i].a[l]]=min(zz[p[i].a[j]].s[p[i].a[l]],p[i].t[j]+p[i].t[l]);
                    zz[p[i].a[l]].s[p[i].a[j]]=min(zz[p[i].a[l]].s[p[i].a[j]],p[i].t[j]+p[i].t[l]);
                }
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            for(int l=min(i,j);l<=max(i,j);l++){
                zz[i].s[j]=min(zz[i].s[j],zz[min(i,j)].s[l]+zz[l].s[max(i,j)]);
                zz[j].s[i]=min(zz[j].s[i],zz[min(i,j)].s[l]+zz[l].s[max(i,j)]);
            }
        }
    }

    for(int i=1;i<=q;i++){
        int st;
        int de;
        scanf("%d",&st);
        scanf("%d",&de);
        printf("%d\n",zz[st].s[de]+w[st]+w[de]);
    }
    return 0;
}

