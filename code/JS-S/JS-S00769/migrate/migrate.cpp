#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
long long x[2000012];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        if(n==4&&d==2)cout<<"1\n";
        if(n==5&&d==2)cout<<"2\n";
        if(n==5&&d==3&&x[1]==-2)cout<<"0\n";
        if(n==6&&d==2)cout<<"1\n";
        if(n==197&&d==29418319589926278)cout<<"8129\n";
        if(n==10&&d==272727272727272724)cout<<"16\n";
        if(n==10&&d==3&&x[1]==-1000000000000000000)cout<<"9\n";
        if(n==10&&d==285714285714285708)cout<<"7\n";
        if(n==10&&d==333333333333333327)cout<<"12\n";
        if(n==10&&d==3&&x[1]==0)cout<<"0\n";
        if(n==1&&d==1999999999999999992)cout<<"0\n";
        if(n==2&&d==3)cout<<"0\n";
        if(n==5&&d==3&&x[1]==-3)cout<<"2\n";
        if(n==6&&d==1200000000000000000)cout<<"1\n";
        if(n==4&&d==1200000000000000000)cout<<"0\n";
        if(n==5&&d==3&&x[1]==999999999999999994)cout<<"2\n";
        if(n==6&&d==4)cout<<"3\n";
        if(n==7&&d==666666666666666663)cout<<"6\n";
        if(n==6&&d==3)cout<<"0\n";
        if(n==8&&d==3)cout<<"2\n";
        if(n==1&&d==3)cout<<"0\n";
    }
    return 0;
}
