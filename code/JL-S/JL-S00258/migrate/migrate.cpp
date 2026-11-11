#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,num,top[200001][200001];
int x[200001];
int bk[200001][200001][200001];
void dfs(int i){
    if(i>=n) return;
    for(int sum=x[i],z=1;d>=sum;sum+=x[i+z],z++){
        bk[i][i+z][top[i][i+z]++]=x[i+z]-x[i];
        dfs(i+z);
    }

}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        dfs(1);
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(top[i][j]!=0){
                    for(int z=1,b=0;z<=top[i][j]&&b==0;z++){
                        for(int zz=z;zz<=top[i][j];zz++){
                            if(bk[i][j][z]==bk[i][j][zz]){
                                num++;
                                b++;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    fclose(stdin);
    fclose(stdout);



    return 0;
}
