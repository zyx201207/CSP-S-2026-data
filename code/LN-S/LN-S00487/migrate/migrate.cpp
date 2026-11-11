#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int a,b,c[100005],d[100005][100005],p;
    cin>>a>>b;
    for(int i=0;i<b;i++){
        cin>>c[i];
        for(int j=1;j<=c[i];j++){
            cin>>d[j][i];
        }

    }
    cin>>p;
    for(int i=0;i<b;i++){
        if(c[i]==0){
            cout<<0;
        }else{
            if(c[i]%2==0){
                cout<<c[i]/p-1;
            }else{
                cout<<c[i]/p;
            }

        }
    }
    return 0;
}
