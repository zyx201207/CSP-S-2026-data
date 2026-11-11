#include<bits/stdc++.h>
using namespace std;
long c,t,n,d,x[2000010];
int main()
{
    //freopen("migrate.in","r",stdin);
    //freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        for(int j=1;j<=n;j++){
            cin>>x[j];
        }
        if(d>=(x[2]-x[1])*2)
            cout<<n-3;
        else
            cout<<0;
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

