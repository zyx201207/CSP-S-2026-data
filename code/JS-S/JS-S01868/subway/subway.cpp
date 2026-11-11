#include<bits/stdc++.h>
using namespace std;
long long w[500005];
int a[5005][5005];
int cnt=INT_MAX;
bool u[10005][10005];
int c,n,m,d,q;

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        int b[500005],t[500005];
        for(int j=1;j<=k;j++){
            cin>>b[j]>>t[j];
        }
        for(int j=1;j<=k;j++){
            for(int k=1;k<=j;k++){
            if(a[b[j]][b[k]]==0)a[b[j]][b[k]]=t[j];
            }
        }

    }

    while(q--){
        int x,y;
        cin>>x>>y;
        cout<<w[x]+w[y]+a[x][x]+a[y][y]<<endl;
    }
    return 0;
}
