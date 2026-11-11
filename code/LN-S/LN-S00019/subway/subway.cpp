#include<bits/stdc++.h>
using namespace std;
const int R = 510;
const int N = 500010;
const int D = 22;
const long long MaxMax = LONG_MAX;
long long a[N],cnt[N],Floyed[R][R];
struct ZJH{
    int num,bcn;
}e[N][D];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    /*get in*/
    cin>>c>>n>>m>>d>>q;
    for(int i = 1;i <= m;i++){
        cin>>a[i];
    }
    int u,t,k;
    for(int i = 1;i <= n;i++){
        cin>>k;
        for(int j = 1;j <= k;j++){
            cin>>u>>t;
            cnt[u]++;
            e[u][cnt[u]].num = t;
            e[u][cnt[u]].bcn = i;
        }
        for(int j = 1;j <= n;j++){
            Floyed[i][j] = MaxMax;
        }
    }
    /*add edge*/
    for(int i = 1;i <= m;i++){
        for(int j = 1;j < cnt[i];j++){
            for(int k = j+1;k <= cnt[i];k++){
                Floyed[e[i][j].bcn][e[i][k].bcn] = e[i][j].num + e[i][k].num;
                Floyed[e[i][k].bcn][e[i][j].bcn] = Floyed[e[i][j].bcn][e[i][k].bcn];
            }
        }
    }
    /*floyed*/
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(i == j){
                Floyed[i][j] = 0;
                continue;
            }
            for(int k = 1;k <= n;k++){
                if(Floyed[i][k] == MaxMax || MaxMax == Floyed[k][j]){
                    continue;
                }
                Floyed[i][j] = min(Floyed[i][j],Floyed[i][k] +Floyed[k][j]);
            }
        }
    }
    /*complete*/
    long long mmin;
    for(int i = 1;i <= q;i++){
        cin>>u>>t;
        mmin = MaxMax;
        for(int j = 1;j <= cnt[u];j++){
            for(int kk = 1;kk <= cnt[t];kk++){
                mmin = min(mmin,Floyed[e[u][j].bcn][e[t][kk].bcn]+e[u][j].num+e[t][kk].num);
            }
        }
        cout<<mmin+a[u]+a[t]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//Floyed
