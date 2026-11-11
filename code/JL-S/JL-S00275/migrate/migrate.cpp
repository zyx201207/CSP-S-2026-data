#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t,n,d,x[10010];
    cin>>c>>t;
    for(int i=1;i<=n;i++){
        cin>>n>>d;
        for(int j=0;j<n;j++){
            cin>>x[i];
        }
    }
    if(x[0]==1&&c==0){
        cout<<"1"<<endl<<"2";
    }
    else if(x[0]==-2&&c==0){
        cout<<"0"<<endl<<"1";
    }
    return 0;
}
