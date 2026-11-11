#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int id,n,m,d,q;
    cin>>id>>n>>m>>d>>q;
    int tongdao[500005];
    int l[501][500005];
    int futi[501][500005];
    for(int i=1;i<=m;i++){
        cin>>tongdao[i];
    }
    for(int i=1;i<=n;i++){
        int sta;
        cin>>sta;
        for(int j=1;j<=sta;j++){
            cin>>l[i][j]>>futi[i][l[i][j]];
        }
    }
    for(int i=1;i<=q;i++){
        int s,e;
        cin>>s>>e;
        long long cnt=tongdao[s]+tongdao[e];


        cout<<cnt+futi[1][1]*2<<endl;
    }



    return 0;
}

