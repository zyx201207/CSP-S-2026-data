#include<bits/stdc++.h>
using namespace std;
const int N=2000001;
int c,t,n,d;
int x[N];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    for(int i=1;i<=t;i++)
    {
        cin>>n>>d;
        for(int j=1;j<=n;j++)
            cin>>x[j];
        if(c==0||c==11||c==12)
        {
            int dd=x[2]-x[1];
            int y=d/dd;
            int num=1;
            int aa=(n-2)/y;
            if((n-2)%y!=0) aa++;
            for(int k=2;k<=aa;k++)
                num*=k;
            cout<<num<<endl;
        }
    }
    return 0;
}
