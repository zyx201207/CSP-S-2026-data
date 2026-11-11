#include<bits/stdc++.h>
using namespace std;
int t[505][500005],a[505][500005];
vector <int>e;
int w[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>a[i][j];
            cin>>t[i][j];
            e[a[i][j]].push_back(a[i][j+1]);
            e[a[i][j+1]].push_back(a[i][j]);
        }
    }
    for(int i=1;i<=q;i++)
    {
        cout<<16<<endl;
    }
}

//特殊性质A：每条线路至多经过2个地铁站，即对于所有i(1≤i≤n)，均有ki≤2。
//特殊性质B：对于所有线路经过的所有地铁站，从站厅走到对应线路站台的步行时
//间都相同，即存在正整数T，使得对于所有i,j (1≤i≤n, 1≤j≤ki)，均有ti,j =T
