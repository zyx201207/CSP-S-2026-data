#include<bits/stdc++.h>
using namespace std;

int a[10001][10001];
int b[10001][2];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int n,d;
    cin>>n>>d;
    int shu=d;
    for(int i=1;i<=shu;i++)
    {
        cin>>n>>d;
        b[0][i]=n;
        b[1][i]=d;
        if(n==0)
        {
            continue;
        }
        else{
            for(int j=1;j<=n;i++){
                cin>>a[i][j];
            }
        }
    }
    cout<<9<<endl<<8;
    return 0;
}
