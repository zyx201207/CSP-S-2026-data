#include<bits/stdc++.h>
using namespace std;

int main()
{
    prev("migrate.in");
    prev("migrate.out");
    int c,t,k=0,x=0;
    cin>>c>>t;
    int n,d;
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        int a[100000010];
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int j=1;j<=d;j++){
            if((a[i+j]-a[i])%d==0) k++;
            if(k==2) x++;
        }
        cout<<x<<endl;
    }
    return 0;
}