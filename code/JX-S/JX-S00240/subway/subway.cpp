#include<bits/stdc++.h>
using namespace std;


int main(){
    int c,n,m,d,q;
    long long ans=0;
    int pp[1000000],v=0;
    long long aa=0,p[500][500010];
    long long w[500010],a[500][500010];

    cin>>c>>n>>m>>d>>q;
    int r[100010][3];
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i][0];
        int uuuu;
        for(int o=1;o<=a[i][0];o++){
            cin>>a[i][0+o];
            cin>>uuuu;
            p[i][a[i][0+o]]=uuuu;
        }
    }
    for(int i=1;i<=q;i++){
            cin>>r[i][1]>>r[i][2];
    }
    bool qq=0;
    long long ma=0;
    for(int i=1;i<n;i++){
        if(a[i][0]!=2)qq=1;
    }
    if(n==2){
        for(int i=1;i<=m;i++){
            if(p[i][1]>0&&p[i][2]>0){
                v++;
                pp[v]=p[1][i]+p[2][i];
            }
        }
        sort(pp,pp+v);
        int x=0,y=0;
        ans=0;
        for(int i=1;i<=q;i++){
            x=r[i][1];
            y=r[i][2];
            if(p[1][x]>0&&p[1][y]>0){
                ans+=w[x]+p[1][x]+p[1][y]+w[y];
            }
            else if(p[2][x]>0&&p[2][y]>0){
                ans+=w[x]+p[1][x]+p[1][y]+w[y];
            }
            else{
                ans+=w[x]+p[1][x]+p[1][y]+w[y]+pp[0];
            }
        }
    }

    cout<<ans;
    return 0;
}
