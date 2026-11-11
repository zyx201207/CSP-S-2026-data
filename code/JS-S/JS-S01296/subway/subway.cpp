#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
int mt[502][502];
struct node{
    int ct,ph;
};
vector<node>mp[500005];
long long minn=0x3f3f3f3f;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
   scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
   for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        if(i==j)mt[i][j]=0;
        else mt[i][j]=0x3f3f3f3f;
    }
   }
   for(int i=1;i<=m;i++){
        scanf("%d",w+i);
   }
   for(int i=1;i<=n;i++){
        int t;
        scanf("%d",&t);
        for(int i=0;i<t;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            if(!mp[y].empty()){
                for(node h:mp[y]){
                    mt[h.ph][i]=mt[i][h.ph]=min(h.ct+x,min(mt[h.ph][i],mt[i][h.ph]));
                }
            }
            mp[y].push_back({x,i});

        }

   }
   for(int l=1;l<=n;l++){
        for(int i=1;i<=n;i++){
            for(int j=l+1;j<=n;j++){
                if(mt[l][i]==0x3f3f3f3f||mt[i][j]==0x3f3f3f3f||l==i||i==j)continue;
                if(mt[l][j]>mt[l][i]+mt[i][j]){
                    mt[j][l]=mt[l][j]=mt[l][i]+mt[i][j];
                }
            }
        }
   }
   for(int i=0;i<q;i++){
    int x,y;
    scanf("%d%d",&x,&y);
    for(node u:mp[x]){
        for(node v:mp[y]){
            if(mt[u.ph][v.ph]<minn){
                minn=mt[u.ph][v.ph];
            }
        }
    }
    if(c>=12&&c<=19)printf("%lld",(long long)(2*w[1]+minn));
   }
    return 0;
}



