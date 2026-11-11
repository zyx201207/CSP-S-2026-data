#include<bits/stdc++.h>
using namespace std;
char a[3],b[3],x[4],y[4];
int sum1,sum2,ans1,ans2,ans3,ans4;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i=1;i<=2;i++)
        cin>>a[i];
    for(int i=1;i<=3;i++)
        cin>>x[i];
    for(int i=1;i<=2;i++)
        cin>>b[i];
    for(int i=1;i<=3;i++)
        cin>>y[i];
    for(int i=1;i<=2;i++)
    {
        if(a[i]==b[i])
        {
            sum1++;
            continue;
        }
        else
        {
            cout<<"0000";
            return 0;
        }
    }
    if(sum1==2)
        ans1=1;
    for(int i=1;i<=2;i++)
    {
        if(x[i]==y[i])
        {
            sum2++;
            continue;
        }
        else
        {
            cout<<1000;
            return 0;
        }
    }
    if(sum2==2)
        ans2=1;
    else
        ans2=0;
    if((x[3]=='A'&&(y[3]=='B'||y[3]=='C'))||(x[3]=='B'&&(y[3]=='A'||y[3]=='C'))||(x[3]=='C'&&(y[3]=='B'||y[3]=='A'))||(x[3]=='D'&&y[3]=='F')||(x[3]=='E'&&y[3]=='F'))
        ans3=1;
    else{
        cout<<1100;
        return 0;
    }
    if((x[3]=='A'&&y[3]=='B')||(x[3]=='B'&&(y[3]=='C'||y[3]=='A'))||(x[3]=='C'&&y[3]=='B')||(x[3]=='D'&&y[3]=='F')||(x[3]=='F'&&y[3]=='D'))
        ans4=1;
    cout<<ans1<<ans2<<ans3<<ans4;
    return 0;
}
