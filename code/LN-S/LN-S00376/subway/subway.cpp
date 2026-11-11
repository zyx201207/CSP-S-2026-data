#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
long long lmin = 1e12+7;
long long c,n,m,d,q,w1,k1,t1,a1,xn,yi;
vector <long long> w,k,a[maxn],t[maxn],x,y,ans;
struct node{
    long long way1,line;
} way[maxn][maxn];
void find(long long f,long long l,long long target){
    if(f == target){
        lmin = min(lmin,l);
        return;
    }
    for(long long i = 1;i<=maxn;i++){
        if(way[f][i].way1 == 0){
            continue;
        }
        find(i,++l,target);
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(way,0,sizeof(way));
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i<=m;i++){
        cin >> w1;
        w.push_back(w1);
    }
    for(int i = 1;i<=n;i++){
        cin >> k1;
        k.push_back(k1);
        for(long long j = 1;j<=k1*2;j++){
            if(j%2 == 1){
                cin >> a1;
                a[i].push_back(a1);
            }else{
                cin >> t1;
                t[i].push_back(t1);
            }
        }
    }
    for(int i = 1;i<=q;i++){
        cin >> xn >> yi;
        x.push_back(xn);
        y.push_back(yi);
    }
    for(long long i = 1;i<=n;i++){
        for(long long j = 1;j<=a[i].size();j++){
            for(long long s = j+1;s<=a[i].size();s++){
                way[j][s].way1 = 1;
                way[j][s].line = i;
            }
        }
    }
    for(int i = 0;i<q;i++){
        if(way[x[i]][y[i]].way1 == 1){
            cout << w[x[i]-1]+w[y[i]-1]+t[way[x[i]][y[i]].line][x[i]-1]+t[way[x[i]][y[i]].line][y[i]-1] << endl;
        }
        if(c>=12 && c<= 19){
            find(x[i],-1,y[i]);
            cout << w[x[i]-1]+w[y[i]-1]+t[1][0]*2*(lmin+1);
        }
    }
    //0 1 3 20 1
    //2 3 2
    //3 1 2 2 3 3 2
    //1 3
    //8
    fclose(stdin);
    fclose(stdout);
    return 0;
}
