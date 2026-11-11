#include<bits/stdc++.h>


using namespace std;

int c;
int t;
int n;
int d;
int x[10000];
int dfs(int a,int b,int & h){
   // printf("   %d  %d\n",a,b);
    int ans = 1000000000;
    int hh;
    int fhh =0 ;


    if(a == b){
        h = 1;
        return 0;
    }

    for(int i = a+1;i<=b && x[i] - x[a] <= d;i++){

        int g = dfs(i,b,hh);
        g += 1;
        if(g < ans){

            ans = g;
            fhh = hh;
        }else if(g ==  ans){
            fhh += 1;

        }


    }
    h = fhh;

    return ans;

}
int main(){

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);


    scanf("%d%d",&c,&t);
    for(int i =1;i<=t;i++){
        int fff = 0;

        scanf("%d%d",&n,&d);
        for(int j = 1;j<=n;j++){

            scanf("%d",x+j);
        }
        for(int j = 1;j<=n;j++){
            for(int k = j+1;k<=n;k++){
                int h = 0;
                dfs(j,k,h);

                if(h >= 2){

                    //printf("%d %d\n",j,k);
                    fff++;

                }

            }

        }
        printf("%d\n",fff);

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
