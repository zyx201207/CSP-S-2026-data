#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("subway.out","w",stdout);
    freopen("subway.in","r",stdin);
    long long c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    long long w[m],a[m][m][n],z[q][2];
    for(int i=0;i<m;i++){
        cin>>w[i];
    }
    for(int i=0;i<n;i++){
        int b,x,y;
        cin>>b;
        for(int j=0;j<b;j++){
            cin>>x>>y;
            x--;
            y--;
            a[j][x][i]=y;
        }
    }
    for(int i=0;i<q;i++){
        for(int j=0;j<2;j++){
            cin>>z[i][j];
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
