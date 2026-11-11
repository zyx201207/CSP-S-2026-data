#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int x[N];
int y[N];
int c,t;
int n,d,m;
int x1,x2;
int main(){
    cin>>n>>d>>c>>t>>m;
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    for(int i=1;i<=n;i++){
        scanf("%d",&x[i]);
    }
    for(int i=1,j=1;j<=n;j++){
        if(x[i]-x[j]<=d){
            int c=x[i]=x[j];

        }
    }
    for(int u=1,v=1;v<=n;v++){
        for(int l=1;l<=(m-1);l++){
            y[l]=y[l]+1;
            d=m-1;
            y[l]=d;
        }
    }
    int u=1;
    int v=1;
    if(u<=v&&v<=n){
        int u=c;
        int v=d;

    }
    cout<<u<<endl;
    cout<<v<<endl;
    return 0;
}
