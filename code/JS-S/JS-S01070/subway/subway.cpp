#include<bits/stdc++.h>
using namespace std;
long long x,y,sumt;
int c, n, m, d, q;
int w[500010],k[510][500010],t[510][500010],zha[500010][22],znumber[500010];
bool point[500010],line[510];
bool in(int a[],int b,int len){
    for(int i = 1;i<=len;i++){
        if(a[i]==b)return 1;
    }
    return 0;
}
void bfs(int num,long long su){
    if(num == y){
        sumt = min(su,sumt);
        return ;
    }
    for(int i = 1;i<=znumber[num];i++){
        if(!line[zha[num][i]]){
            line[zha[num][i]] = 1;
            for(int j = 1;j<=k[i][0];j++){
                point[k[i][j]] = 1;
                if(k[i][j]!=num&&znumber[k[i][j]]>1){
                    bfs(k[i][j],su+t[zha[num][i]][k[i][j]]);
                    point[k[i][j]] = 0;
                }
            }
            line[zha[num][i]] = 0;
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin >> c;

    cin >> n >> m >> d >> q;
    for(int i = 1;i<=m;i++)cin >> w[i];
    for(int i = 1;i<=n;i++){
        cin >> k[i][0];
        for(int j = 1;j<=k[i][0];j++){
            cin >> k[i][j] >> t[i][j];
            znumber[k[i][j]]++;
            zha[k[i][j]][znumber[k[i][j]]] = k[i][0];
        }
    }
    for(int i = 1;i<=q;i++){
        cin >> x >> y;
        sumt += w[x] + w[y];
        point[x] = 1;
        bfs(x,sumt);
        cout << sumt << endl;
    }
    return 0;
}
