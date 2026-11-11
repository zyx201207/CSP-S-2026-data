#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,cnt;
int a[3000000];
int b[3000000][3];
bool check(int x,int y)
{
    int cnt=0,tmp=x;
    while(b[tmp][0]<y)
    {
        if(((b[b[tmp][0]][0]==b[b[tmp][1]][0])||b[b[tmp][1]][0]>=y)&&b[b[tmp][0]][0]!=b[b[tmp][2]][0])
            cnt++;
        tmp=b[tmp][0];
    }
    if(cnt==1) return true;
    return false;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        memset(a,0x3f3f3f3f,sizeof(a));
        a[0]=-1e9,cnt=0;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        b[n][0]=0,b[n][1]=0,b[n][2]=0;
        if(a[1]<0)
            for(int i=1;i<=n;i++)
                a[i]+=abs(a[1]);
        for(int i=1;i<n;i++)
        {
            for(b[i][0]=i;a[b[i][0]+1]<=a[i]+d;b[i][0]++){}
            b[i][1]=b[i][0]-1;
            b[i][2]=b[i][1]-1;
            if(b[i][1]<=i) b[i][1]=0,b[i][2]=0;
            else if(b[i][2]<=i) b[i][2]=0;
        }
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(check(i,j))
                    cnt++;
        cout<<cnt<<endl;
    }
    return 0;
}
