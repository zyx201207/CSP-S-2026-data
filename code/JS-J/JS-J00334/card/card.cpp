#include<bits/stdc++.h>
using namespace std;
int n,m,a[500050];
bool flag;
int f[300050];
int b[500050];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if (a[i-1] > a[i]) flag = true;
        f[a[i]]++;
    }
    if (!flag){
        for(int i=1;i<=n;i++) {
            f[i] += f[i-1];
            cout<<f[i]<<" ";
        }
        return 0;
    }
    if (m == 1){
        for(int i=0;i<n;i++) cout<<1<<" ";
        return 0;
    }
    memset(f,0,m+5);
    for(int i=0;i<n;i++){
        memset(b,0,n+5);
        int idx = 0;
        for(int j=i+1;j<=n;j++){
            for(int z=0;z<idx;z++) {
                if (b[z] == a[j]){
                    idx = z;
                    break;
                }
            }
            b[idx++] = a[j];
            //cout<<idx-1<<" "<<a[j+1]<<endl;
        }
        for(int i=0;i<idx;i++) f[b[i]]++;
    }

    for(int i=1;i<=m;i++) cout<<f[i]<<" ";
    return 0;
}
//neng2shang4 270 ma1,gan3jve2nv3nv3li4hai2you3xi1wang4
//mao3si4da4cha4bu2cha4,zhi4yao4mei2bao2......jiu4hai2you3xi1wang4
//gan3jve2 T3 de2fen1bi3 T2 gao1......
