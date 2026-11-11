#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[100001],t[500][500],a[500][500],ss=0,x,y;
void dd(int k,int s){
    if(k==y){
        if(s>ss)ss=s;
        return;
    }
    s+=t[k][1];
    for(int i=2;i<=a[k][0];i++){
        if(a[a[k][i]][0]!=0)dd(a[k][i],s+t[k][i]);
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;

    for(int i=1;i<=m;i++){
        cin>>w[i];
        a[1][0]=t[1][0]=0;
    }
    for(int i=1;i<=n;i++){
        int g;
        cin>>g;
        for(int j=1;j<=g;j++){
            cin>>a[i][++a[i][0]]>>t[i][++t[i][0]];
        }
    }
    for(int o=1;o<=q;o++){
        cin>>x>>y;
        ss=0;
        dd(x,0);
        cout<<ss+w[x]+w[y]<<endl;
    }
    return 0;
}
/*
0 2 5 20 2
 4 1 9 2 5
 3 1 5 2 7 4 6
 3 2 3 3 4 5 7
 1 3
 1 2
*/
