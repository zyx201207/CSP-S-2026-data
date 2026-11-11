#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    int n,d;
    int x[10001];
    int cnt=0,sum=0,num=0;
    int jishu=0;
    for(int i=1; i<=t; i++)
    {
        cin>>n>>d;
        cin>>x[i];
    }
    for(int i=1;i<=t;i++){
        for(int j=1;j<=n;j++){
            if(x[i+d]-x[i]==)
                    cnt=a[i+1]-a[i];

            if(a[i+2]-a[i]<=d)
                    num=a[i+2]-a[i];

            if(a[i+2]-a[i+1]<=d)
                    sum=a[i+2]-a[i+1];
            //if(cnt==num)
        }
    }
    cout<<sum;
    return 0;
}
