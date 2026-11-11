#include<bits/stdc++.h>
using namespace std;

int t,n,d;
vector<int> x;
vector<vector<int>> g;

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d %d",&t,&t);
    while(t--) {
        x.clear();
        scanf("%d %d",&n,&d);
        for(int i=0;i<n;i++) {
            int a;scanf("%d",&a);
            x.push_back(a);
        }
        g.resize(n);
        for(int i=0;i<n;i++) {
            g[i].resize(n,0);
            int j = i+1;
            while(abs(x[j]-x[i])<=d) {
                g[i][j] = g[j][i] = 1;
            }
        }
        for(int k=0;k<n;k++) {
            for(int i=0;i<n;i++) {
            if(i!=k) {
                for(int j=0;j<n;j++) {
                if(i!=j && j!=k) {
                    g[i][j] =min(g[i][k]+g[k][j],g[i][j]);
                }
                }
            }
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                ;
            }
        }
        printf("0\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
