#include<bits/stdc++.h>
using namespace std;
int w[500005];
int k[500005];
int a[505][500005];
int t1;
int t[505][500005];
int x[100005];
int y[100005];
int ans=0;
int to1[500005];
int to2[500005];
int to3[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t1;
            t[i][a[i][j]]=t1;
            if(n==2){
                if(i==1){
                    to1[a[i][j]]++;
                }else{
                    to2[a[i][j]]++;
                }
                to3[a[i][j]]++;
            }
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x[i]>>y[i];
    }
    if(n<=2){
        int change=INT_MAX;
        for(int i=1;i<=m;i++){
            if(to3[i]==2){
                change=min(change,t[1][i]+t[2][i]);
            }
        }
        if(n==1){
            for(int i=1;i<=q;i++){
                cout<<a[1][x[i]]+a[1][y[i]]<<endl;
            }
            return 0;
        }else{
            for(int i=1;i<=q;i++){
                if(to1[x[i]]==1 && to1[y[i]]==1 && to2[x[i]]==1 && to2[y[i]]==1){
                    cout<<min(min(min(w[x[i]]+w[y[i]]+t[1][x[i]]+t[1][y[i]],w[x[i]]+w[y[i]]+t[2][x[i]]+t[2][y[i]]),w[x[i]]+w[y[i]]+t[1][x[i]]+t[2][y[i]]+change),w[x[i]]+w[y[i]]+t[2][x[i]]+t[1][y[i]]+change);
                }else if(to1[x[i]]==1 && to1[y[i]]==1 && to2[y[i]]==1){
                    cout<<min(w[x[i]]+w[y[i]]+t[1][x[i]]+t[1][y[i]],change+w[x[i]]+w[y[i]]+t[1][x[i]]+t[2][y[i]])<<endl;
                }else if(to1[x[i]]==1 && to1[y[i]]==1 && to2[x[i]]==1){
                    cout<<min(w[x[i]]+w[y[i]]+t[1][x[i]]+t[1][y[i]],change+w[x[i]]+w[y[i]]+t[2][x[i]]+t[1][y[i]])<<endl;
                }else if(to2[x[i]]==1 && to2[y[i]]==1 && to1[y[i]]==1){
                    cout<<min(w[x[i]]+w[y[i]]+t[2][x[i]]+t[2][y[i]],change+w[x[i]]+w[y[i]]+t[2][x[i]]+t[1][y[i]])<<endl;
                }else if(to2[x[i]]==1 && to2[y[i]]==1 && to1[x[i]]==1){
                    cout<<min(w[x[i]]+w[y[i]]+t[2][x[i]]+t[2][y[i]],change+w[x[i]]+w[y[i]]+t[1][x[i]]+t[2][y[i]])<<endl;
                }else if(to1[y[i]]==1 && to2[x[i]]==1){
                    cout<<w[x[i]]+w[y[i]]+change+t[2][x[i]]+t[1][y[i]]<<endl;
                }else{
                    cout<<w[x[i]]+w[y[i]]+change+t[1][x[i]]+t[2][y[i]]<<endl;
                }
            }
            return 0;
        }
    }
    return 0;
}
