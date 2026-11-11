#include<bits/stdc++.h>
using namespace std;


struct f{
long long s;
long long f=20000010;
long long fz=0;
long long h=0;
long long d=1;
};
f c[20000005];
void dfs(long long a,long long b,long long x,long long cnt,long long z){
    if(x>c[a].s)
        return ;

    for(int i=1;i<=b;i++){

    if(c[i].f==cnt){
        if(c[x].fz!=z){
            c[x].d++;
            c[x].fz=z;
        }
    }

    else{
    c[x].f=min(c[x].f,cnt);
    c[x].d=1;

    }
    dfs(a,b,x+i,cnt++,z+c[x].s+c[x+i].s);

    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int u,t;
    cin >> u >> t;
    for(int i=1;i<=t;i++){
            long long a,b;
        cin >> a >> b;
   long long ans=0;
        for(int j=1;j<=a;j++){
            cin >> c[j].s;
            c[j].f=200000010;
            c[j].fz=2000000000000000000;
            c[j].h=0;
            c[j].d=1;

        }
            dfs(a,b,0,0,0);
            for(int j=1;j<=a;j++){
                if(c[j].d==2){
                    ans++;
           //         cout << "c[j]     "    << c[j].s << endl;
                }
            }
            cout << ans << endl;
    }
    return 0;
}
