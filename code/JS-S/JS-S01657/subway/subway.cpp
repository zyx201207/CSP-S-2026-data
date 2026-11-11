#include<bits/stdc++.h>
using namespace std;

int c;
int n;
int m;
int d;
int q;
long long w[500100];
long long minn(long long a,long long b){

    if(a< b) return a;
    return b;

}
struct targ{

    int tarr;
    long long tt;
    targ(int tarr,long long tt){
        (*this).tarr = tarr;
        (*this).tt = tt;
    }

};


vector<targ> acr[500100];
long long edges[600][600];
long long dist[600][600];
int k;
int x;
int y;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);






    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);

    for(int i = 1;i<=599;i++){

        for(int j = 1;j<=599;j++){
            if(i != j){
                edges[i][j] = 1ll<<31;
                dist[i][j] = 1ll<<62;

            }

        }

    }

    for(int i = 1;i<=m;i++){
        scanf("%lld",w+i);
    }
    for(int i = 1;i<=n;i++){

        scanf("%d",&k);
        int a;
        long long t;
        for(int j = 1;j<=k;j++){
            scanf("%d%lld",&a,&t);
            acr[a].push_back(targ(i,t));
        }




    }

    for(int i = 1;i<=m;i++){
        for(int j1 = 0;j1<(int)acr[i].size();j1++){
            for(int j2 = j1+1;j2<(int)acr[i].size();j2++){
                edges[acr[i][j1].tarr ][acr[i][j2].tarr] =  minn(acr[i][j1].tt +acr[i][j2].tt , edges[acr[i][j1].tarr ][acr[i][j2].tarr]);

                edges[acr[i][j2].tarr ][acr[i][j1].tarr] =  minn(acr[i][j1].tt +acr[i][j2].tt , edges[acr[i][j1].tarr ][acr[i][j2].tarr]);


            }


        }
        //printf("%d     %d %lld\n",i,acr[i][j].tarr,acr[i][j].tt);



    }

    for(int i = 1;i<=n;i++){

        for(int j = 1;j<=n;j++){
            dist[i][j] = edges[i][j];
        }

    }




/*
    for(int  i = 1;i<=n;i++){

        for(int j = 1;j<=n;j++){

            for(int thr = 1;thr<=n;thr++){
                if(thr != i && thr != j && i != j) dist[i][j] = minn(dist[i][j], minn(dist[i][thr] ,dist[thr][i]) + minn(dist[j][thr],dist[thr][j]) );
            }

        }


    }
    */
    for(int  thr = 1;thr<=n;thr++){

        for(int j = 1;j<=n;j++){

            for(int i = 1;i<=n;i++){
                if(thr != i && thr != j && i != j){
                    dist[j][i] = minn(dist[j][i], dist[i][thr] + dist[j][thr] );

                }
            }

        }


    }









/*
    for(int i = 1;i<=n;i++){

        for(int j = 1;j<=n;j++){
            printf("%d  %d  %lld\n",i,j,edges[i][j]) ;
            printf("    %d  %d  %lld\n",i,j,dist[i][j]) ;
        }

    }

*/









    for(int i = 1;i<=q;i++){

        scanf("%d%d",&x,&y);
        long long ans = -1;

        for(int j1 = 0;j1<(int)acr[x].size();j1++){
            for(int j2 = 0;j2<(int)acr[y].size();j2++){

                ans = ans == -1 ? (dist[acr[x][j1].tarr][acr[y][j2].tarr] + acr[x][j1].tt + acr[y][j2].tt) : minn(dist[acr[x][j1].tarr][acr[y][j2].tarr] + acr[x][j1].tt + acr[y][j2].tt,ans);

            }


        }

        printf("%lld\n",ans + w[x] + w[y]);

    }
    fclose(stdin);
    fclose(stdout);

    return 0;

}
